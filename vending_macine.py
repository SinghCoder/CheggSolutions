items = []
credit = 0

def vend():
    a = {'key':'0','item': 'chips', 'price': 1.50, 'stock': 6}
    b = {'key':'1','item': 'cereal', 'price': 1.25, 'stock': 10}
    c = {'key':'2','item': 'pop', 'price': 1.75, 'stock': 12}
    d = {'key':'3','item': 'apple', 'price': 2.50, 'stock': 6}
    e = {'key':'4','item': 'orange', 'price': 1.95, 'stock': 10}
    items.append(a)
    items.append(b)
    items.append(c)
    items.append(d)
    items.append(e)
    credit = 0 # cash in machine

# show items, prices
def show(items):    
    print("Available items in vending machine: ")
    for item in items:
        if item.get('stock') == 0:
            items.remove(item)
        else:
            print('{0} {1} ${2} ({3} available)'.format(item.get('key'), item.get('item'), item.get('price'), item.get('stock')))

if __name__ == "__main__":
    vend()
    buy = True
    # have user choose item
    while buy == True:
        s = input("> Enter items to buy from vending machine or add to add an item: ")
        if s == "items":
            show(items)
            selected = input('>Select an item number(0/1/..) to purchase: ')
            for item in items:
                if selected == item.get('key'):
                    selected_item = item                
                    price = selected_item.get('price')
                    while credit < price:
                        print("MSG: Insufficient Credit")
                        print('CREDIT: $%.2f' % credit)
                        print("Please Enter a 'penny', 'nickel', 'dime' or a 'quarter'")
                        currency={"penny":0.01,"nickel":0.05,"dime":0.1,"quarter":0.25}
                        cred=input('>')
                        credit=credit+currency[cred]
                        print("CREDIT: $%.2f" % credit)

                    print('VENDING OUT:' + selected_item.get('item'))
                    selected_item['stock'] -= 1
                    credit -= price
                    print('return: $%.2f' % credit)
                    credit = 0
                    print('credit: $%.2f' % credit)
                    break
            choice = input("Do you want to purchase more items? (Y/N) : ")
            if choice == "N":
                buy = False
        elif s == "add":
            show(items)
            choice = input("Enter existing to increase stock of an existing item, or add to add a new item: ")
            if choice == "existing":
                key = input("Enter item's key: ")
                amount = int(input("Enter number of items to add: "))
                for item in items:
                    if item.get('key') == key:
                        item['stock'] = item['stock'] + amount
                        break
            elif choice == "add":
                key = input("Enter key of item: ")
                name = input("Enter item's name: ")
                amount = int(input("Enter stock: "))                
                price = float(input("Enter price of the item: "))
                items.append({
                    'key':key,
                    'item':name,
                    'price':price,
                    'stock':amount
                })
            print("New contents of vending machine")
            show(items)