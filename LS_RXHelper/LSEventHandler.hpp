#pragma once
#define bindEEvent(VARI,METHOD,...) VARI.bind(METHOD,METHOD,__VA_ARGS__ )
#define notifyEEvent(VARI,...) VARI.notify(__VA_ARGS__ )
#define unbindEEvent(VARI,ID) VARI.unbind(ID)
template<typename ReturnType, typename ... paramsT >
class EHandlerBase
{
public:
	virtual ReturnType FireEvent(paramsT ... param) = 0;

};


template<typename ReturnType, typename ... paramsT >
class EEventHandler : public EHandlerBase<ReturnType, paramsT...>
{
public:
	EEventHandler(void* method)
	{
		object = method;
	}
	ReturnType FireEvent(paramsT ... params)
	{
		using rEvent = ReturnType(*)(paramsT...);
		return reinterpret_cast<rEvent>(object)(params...);
	}

private:
	void*object;
};

template <typename ReturnT, typename ...ParamT>
class EEvent
{
public:
	EEvent()
	{
	}
	~EEvent()
	{
	}

	// returns event id
	int bind(void*method, ReturnT(*)(ParamT...), ParamT... params)
	{
		events[m_count++] = (new EEventHandler<ReturnT, ParamT...>(method));
		return m_count - 1;
	}
	bool unbind(int id)
	{
		HandlersMap::iterator it = events.find(id);

		if (it == events.end())
			return false;

		delete it->second;
		events.erase(it);
		return true;
	}
	ReturnT notify(ParamT ... param)
	{
		HandlersMap::iterator it = events.begin();
		for (; it != events.end(); it++)
		{
			it->second->FireEvent(param...);
		}
	}

private:
	typedef  std::map<int, EHandlerBase<ReturnT, ParamT...> *> HandlersMap;
	HandlersMap events;
	int m_count=0;
};

/*

EEvent<void, int, int>testevent_args;
EEvent<void>testevent_noargs;
void OnTestEventArgs(int arg1, int arg2)
{
printf("Args : %d,%d\n", arg1, arg2);
}
void OnTestEvent_NO_Args()
{
printf("NO args\n");
}

// conformance option should be disabled
int eventexample(void)
{
bindEEvent(testevent_args, OnTestEventArgs, 1, 2);
int eventid2 = bindEEvent(testevent_noargs, OnTestEvent_NO_Args);


notifyEEvent(testevent_args, 1, 2); // with infinite args
notifyEEvent(testevent_noargs); // no args

if (GetAsyncKeyState(VK_SPACE))
unbindEEvent(testevent_noargs, eventid2);
return 0;
}

*/