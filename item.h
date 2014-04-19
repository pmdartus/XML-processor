#ifndef ITEM_H
#define ITEM_H

class tag;

class Item
{

private:

public:
	Item* parent = 0;
    virtual ~Item();
    
    const Item * getParent() const;
    void setParent(Item *parent);
    virtual void print() = 0;

};

#endif
