#include "CustomerListType.h"
#include "Stock_Inventory.h"
#include <iostream>
#include <vector>
#include <list>
#include "Ui.h"
#include <string>

using namespace std;

UI::UI()
{
	// invlist.load stocks into inventory
}

UI::~UI()
{
	// write stocks from inventory into file
}

void UI::mainMenu()
{
	int option;
		string customername, customeremail, customerID;
	cout << "main menu" << "1)add customer" << "2) remove coustomer"
		<< "3)find customer" << "4) list customer information" << "5) Order menu" << "6) Inventory menu" << endl;
	cin >> option;
switch (option)
{
case 1:		// add customer
	// Need to get potential new customerID

	// after reading in customerID - see if it already exists

	// if it already exists, warn user and go back to customer menu

	// collect rest of customer information
	cout << "enter customer name" << endl;
	// names are notorious for having spaces in them - must use getline
	cin >> customername;
	cout << "enter customer email" << endl;
	cin >> customeremail;
	// build customer and add to customer
	// customerlist.addCustomer(Customer(----,-----,-----));
		break;
case 2:		// remove customer
	// you may want to display list of customerIDs so user can choose one
	cout << "enter customer ID" << endl;
	cin >> customerID;
	// find customer object in customerlist returning iterator pointing to the customer object
	// if found
	//		use customer list remove method passing iterator
	// else
	//		message to user not found

		break;
case 3:		// find customer returning iterator pointing to the customer
	// you may want to display list of customerIDs so user can choose one
	cout << "enter customer ID" << endl;
	cin >> customerID;
	// CustomerType& cust = custlist.getcustomer(customerID)
	break;
// case 4: list customer information
	// you may want to display list of customerIDs so user can choose one
	cout << "enter customer ID" << endl;
	cin >> customerID;
	// CustomerType& cust = custlist.getcustomer(customerID)
	// use customer operator<< to print customer
	break;
// case 5:  order menu
	// orderMenu()
}
}

void UI::orderMenu()
{
	int option, custID;
	cout << "Order Menu" <<
		"1) List Orders for Customer" << endl <<
		"2) Over all orders for all customers" << endl <<
		"3) Add order to customer" << endl << 
		"4) Cancel order for a customer" << endl <<
		"5) Update order for a customer" << endl <<
		endl;
	cin >> option;

	switch (option)
	{
	case 1:    
		
		// list orders for a customer
		cout << "Enter customer ID: ";
		//customerListprint;
		cin >> custID;


		//custMenu(custID);???
		// iterator = find customer
		// if iterator not = customer list end
		//		(*iterator) invoke method printOrders()
		// else
		//		customerid not found
		break;
	case 2:     // list all orders for all customers
		// use for range loop to retrieve each customer
		//		for current customer invoke printOrders() method
		// end loop

		break;
	case 3:		// add an order for a customer
		//customerListprint;
		cin >> custID;
		// Customer& cust = custlist.getcustomer(custID)
		// if cust != emptyCustomer
		//		invoke addOrderData(cust)
		// else
		//		customerid not found
	case 4:		// cancel order
		
		CustomerListType UICL; //Replace this and all references to it with the actual customerListType obj.
		Inventory st; // Replace this and all references to it with the actual inventory obj.


		UICL.print();
		string custID,orderID, canDate;

		cout << "Please enter the Customer ID Number:" << endl;
		cin >> custID;
		CustomerType& cust = UICL.getcustomer(custID);
		
		if (cust.getId() != "")
		{
			cust.printOrderIds();
			cout << "Please enter the orderID:" << endl;
			cin >> orderID;
			Order& ord = cust.getOrder(orderID);
			if (ord.getOrderID() != "")
			{
				try {
				cout << "Please enter the date you wish to cancel:" << endl;
				cin >> canDate;
				Date cDate(canDate);

				if (ord.getDeliveryDate() > cDate)
				{
					for (auto b = ord.orderItems.begin(); b != ord.orderItems.end(); ++b)
					{
						for (auto c = st.stocks.begin(); c != st.stocks.end(); ++c)
						{
							if (orderID == (*c).id())
							{
								st.incrementQuantity((*b).getQuant());
							}
						}
					}
					cust.removeOrder(orderID);

				}
				else
				{
					cout << "Delivery Date already met. Cannot cancel order that's been delivered." << endl;
				}

				}
				catch (exception)
				{
					system("CLS");
					cerr << "Error: Exception " << current_exception << " has been thrown for Invalid Date Entry." << endl
						<< "Date must be in the format mm/dd/yyyy. Exiting program." << endl;
					exit(1);
				}
			}
			else
			{
				cout << "Error: OrderID not found." << endl;
			}
		}
		else
			cout << "CustomerID not found." << endl;
	case 5:			// update order
		//	updateOrderMenu()
	default:
		break;
	}

}

void UI::invMenu()
{
	//int option, custID;
	//cout << "Order Menu" <<
	//	"1) List all items in inventory" << endl <<
	//	"2) Display an item in inventory" << endl <<
	//	"3) Process order from supplier" << endl <<
	//	"4) Generate orders to the suppliers for a given month" << endl <<
	//	"5) Find the high demand items for a period of time - month, qtr, yr" << endl <<
	//	endl;
	//cin >> option;

	//switch (option)
	//{
	//case 1:     // list all items in inventory
	//		invlist.printInventory();
	//		break;
	//case 2:     // display an item in inventory
	//		ask user for itemid
	//		Stock& stk = invlist.findItem(itemid)
	//		stk.printStock()
	//		break;
	//case 3:		//process an order from a supplier
	//		prompt user for filename of order from a supplier
	//		establish an input file using filename from user
	//		check if file was able to open
	//		while more records
	//			read new item information - itemid, qty
	//			Stock& stk = invlist.findItem(itemid)
	//			if stk not emptystock
	//				stk.incrementQuantity(qty)
	//			else
	//				error message
	//			endif
	//		end while
	//		close file
	//		break;
	//case 4:		// Generate orders to the suppliers for a given month
	//		get month and year for order header
	//		vector<SupplierItem> supplist;
	//		for each stock in invlist
	//			if stock.getInStock() < stock.getReorderPoint()
	//				supplist.push_back(SupplierItem(stock.getSupplierID(),
	//						stock.getID(), stock.reorderAmount())
	//			endif
	//		next
	//		supplist.sort
	//		generate report with breaks at supplierID change
	//		break;			
	//case 5:		Find the high demand items for a period of time - month, qtr, yr
	//		vector<pair<string, int>> usage;
	//		get startdate and enddate
	//		for each cust in custlist
	//			for each ord in cust.ordlist
	//				verify that orderdate is between startdate and enddate
	//				if so,
	//					for each orditem in orditemlist
	//						string itdata = orditem.getItemID()
	//						auto& itemiter = find(usage.begin(), usage.end(), 
	//							[itdata](pair<string, int> listel)
	//								{return (listel.first() == itdata); }
	//						if itemiter != usage.end() 
	//							itemiter->second += orditem.getQuant();
	//						else
	//							usage.push_back(make_pair(orditem.getItemID(), orditem.getQuant())
	//						endif
	//					next
	//				endif
	//			next
	//		next
	//						
	//}
}

//void UI::custMenu(int ID)
//{
//	string itemID, qnty;
//	Listinvertory;
//	cin >> itemID
//	if ()
//	{
//
//	}
//}

// addOrderData routine
//void UI::addOrderData(CustomerType& cust)
//      collect orderid, orderdate, deliverydate
//		create order object
//		while more orderitems
//			collect orderitem data - itemid, quantity
//			orderitem reference = ord.findOrderItem(itemid)
//			if orderitem refence != emptyorderitem,
//				orderitem reference.incrementQuantity(quantity)
//			else
//				orderitem neworditem = invlist.checkIfInStock(itemid, quantity)
//				ord.addOrderItem(neworderitem)
//			endif
//			ask if more orderitems
//		end while when no more order items
//		cust.addOrder(order object)
