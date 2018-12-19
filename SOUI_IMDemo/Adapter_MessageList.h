#ifndef __ADAPTER_MESSAGELIST_H__
#define __ADAPTER_MESSAGELIST_H__

#pragma once
#include <helper/SAdapterBase.h>
#include <vector>

#include "GlobalUnits.h"
#include "IAdapterCallback.h"


struct MessageListItemData
{
	int nType;			//0�ļ��������֣�1�������죬2�������죬3���ĺţ�4���ţ�5���ں�
	std::string strID;
};

class CAdapter_MessageList : public SAdapterBase
{
public:
	CAdapter_MessageList(SListView* pOwner, IAdapterLasttalk_Callback* pCB);
	~CAdapter_MessageList(void);

public:
	void AddItem(const int& nType, const std::string& strID);

protected:
	virtual void getView(int position, SWindow* pItem, pugi::xml_node xmlTemplate);\
	virtual int getCount();
	virtual SStringT getColunName(int iCol) const;

	bool OnEventLvSelChangeing(EventLVSelChanging* pEvt);
	bool OnEventItemPanelClick(EventArgs* e);
	bool OnEventItemPanelRClick(EventArgs* e);

private:
	std::vector<MessageListItemData*> m_vecItemInfo;
	SListView*						  m_pOwner;

	IAdapterLasttalk_Callback*        m_pCB;

	MemberFunctionSlot<CAdapter_MessageList, EventArgs>			m_evtItemClick;
	MemberFunctionSlot<CAdapter_MessageList, EventArgs>			m_evtItemRClick;
};

#endif