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
	int m_count;
};

// EXAMPLE USAGE
/*
void testeventccc2()
{
printf("called2\n");
}
void testeventccc()
{
printf("called\n");
}
void testeventccc3()
{
printf("called3\n");
}
EEvent<void>testevent;

int main(void)
{
bindEEvent(testevent, testeventccc);
int id2 =bindEEvent(testevent, testeventccc2);
bindEEvent(testevent, testeventccc3);
while (true)
{
if (GetAsyncKeyState(VK_SPACE))
{
testevent.unbind(id2); // REMOVES EVENT
}
testevent.notify(); // NOTIFY CALLBACKS
Sleep(1000);
}
}
*/