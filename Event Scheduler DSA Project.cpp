#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  
using namespace std;

class Event {
public:
    string title;
    string date;
    int priority;  // 1 = highest, 3 = lowest
    
    
    Event(string t, string d, int p) {
        title = t;
        date = d;
        priority = p;
    }
    
    // Display event
    void display() {
        cout << "Event: " << title << endl;
        cout << "Date: " << date << endl;
        cout << "Priority: " << priority << endl;
        cout << "-------------------" << endl;
    }
};

class EventScheduler {
private:
    vector<Event> events;  // Dynamic array to store events
    
public:
    
    void addEvent() {		// Add new event
        system("cls");
        string title, date;
        int priority;
        
        cout << "\n=== ADD EVENT ===" << endl;
        cin.ignore();
        
        cout << "Enter event title: ";
        getline(cin, title);
        
        cout << "Enter date (DD/MM/YYYY): ";
        getline(cin, date);
        
        cout << "Enter priority (1=High, 2=Medium, 3=Low): ";
		cin >> priority;

		if (cin.fail() || priority < 1 || priority > 3) {
    	cin.clear();
    	cin.ignore(INT_MAX, '\n');
    	cout << "Invalid input. Setting default priority = 2 (Medium)." << endl;
    	priority = 2;
		}

        
        Event newEvent(title, date, priority);
        events.push_back(newEvent);
        
        cout << "\nEvent added successfully!" << endl;
        system("pause");
    }
    
    void viewAllEvents() {		    // View all events 

        system("cls");
        cout << "\n=== ALL EVENTS ===" << endl;
        
        if (events.empty()) {
            cout << "No events found!" << endl;
            system("pause");
            return;
        }
        
        for (int i = 0; i < events.size(); i++) {
            cout << "Event #" << (i + 1) << ":" << endl;
            events[i].display();
        }
        system("pause");
    }
    
    void sortByPriority() {		//Sort Events
        system("cls");
        cout << "\n=== SORTING BY PRIORITY ===" << endl;
        
        if (events.empty()) {
            cout << "No events to sort!" << endl;
            system("pause");
            return;
        }
        
        for (int i = 0; i < events.size() - 1; i++) {
            for (int j = 0; j < events.size() - i - 1; j++) {
                if (events[j].priority > events[j + 1].priority) {
                    Event temp = events[j];
                    events[j] = events[j + 1];
                    events[j + 1] = temp;
                }
            }
        }
        
        cout << "Events sorted by priority!" << endl;
        cout << "\n=== SORTED EVENTS ===" << endl;
        
        for (int i = 0; i < events.size(); i++) {
            cout << "Event #" << (i + 1) << ":" << endl;
            events[i].display();
        }
        system("pause");
    }
    
    void searchEvent() {		//Search Event
        system("cls");
        
        if (events.empty()) {
            cout << "No events to search!" << endl;
            system("pause");
            return;
        }
        
        string searchTitle;
        cout << "\n=== SEARCH EVENT ===" << endl;
        cin.ignore();
        cout << "Enter event title: ";
        getline(cin, searchTitle);
        
        bool found = false;
        
        for (int i = 0; i < events.size(); i++) {
            if (events[i].title == searchTitle) {
                cout << "\nEvent Found at position " << (i + 1) << ":" << endl;
                events[i].display();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "\nEvent not found!" << endl;
        }
        
        system("pause");
    }
    
    void deleteEvent() {		//Delete Event
        system("cls");
        
        if (events.empty()) {
            cout << "No events to delete!" << endl;
            system("pause");
            return;
        }
        
        string deleteTitle;
        cout << "\n=== DELETE EVENT ===" << endl;
        cin.ignore();
        cout << "Enter event title to delete: ";
        getline(cin, deleteTitle);
        
        for (int i = 0; i < events.size(); i++) {
            if (events[i].title == deleteTitle) {
                events.erase(events.begin() + i);
                cout << "\nEvent deleted successfully!" << endl;
                system("pause");
                return;
            }
        }
        
        cout << "\nEvent not found!" << endl;
        system("pause");
    }
    
    void getHighestPriority() {		//Highest priority
        system("cls");
        cout << "\n=== HIGHEST PRIORITY EVENT ===" << endl;
        
        if (events.empty()) {
            cout << "No events available!" << endl;
            system("pause");
            return;
        }
        
        int highestIndex = 0;
        
        for (int i = 1; i < events.size(); i++) {
            if (events[i].priority < events[highestIndex].priority) {
                highestIndex = i;
            }
        }
        
        cout << "Most important event:" << endl;
        events[highestIndex].display();
        system("pause");
    }
    
    void showStats() {		//Sho stats
        system("cls");
        cout << "\n=== STATISTICS ===" << endl;
        cout << "Total events: " << events.size() << endl;
        
        if (events.empty()) {
            system("pause");
            return;
        }
        
        int high = 0, medium = 0, low = 0;
        
        for (int i = 0; i < events.size(); i++) {
            if (events[i].priority == 1) high++;
            else if (events[i].priority == 2) medium++;
            else low++;
        }
        
        cout << "High priority: " << high << " events" << endl;
        cout << "Medium priority: " << medium << " events" << endl;
        cout << "Low priority: " << low << " events" << endl;
        system("pause");
    }
};

int main() {
    EventScheduler scheduler;
    int choice;
    
    do {
        system("cls"); 
        cout << "================================" << endl;
        cout << "   SIMPLE EVENT SCHEDULER" << endl;
        cout << "   DSA Concepts Demonstration" << endl;
        cout << "================================" << endl;
        
        cout << "\n=== MAIN MENU ===" << endl;
        cout << "1. Add Event" << endl;
        cout << "2. View All Events" << endl;
        cout << "3. Sort by Priority" << endl;
        cout << "4. Search Event" << endl;
        cout << "5. Delete Event" << endl;
        cout << "6. Get Highest Priority" << endl;
        cout << "7. Show Statistics" << endl;
        cout << "8. Exit" << endl;
        cout << "\nChoose option (1-8): ";
        
        cin >> choice;
        
        if (cin.fail()) {
    		cin.clear();
    		cin.ignore(INT_MAX, '\n');
    		choice = -1;  // invalid to trigger default case
			}
        
        switch (choice) {
            case 1:
                scheduler.addEvent();
                break;
            case 2:
                scheduler.viewAllEvents();
                break;
            case 3:
                scheduler.sortByPriority();
                break;
            case 4:
                scheduler.searchEvent();
                break;
            case 5:
                scheduler.deleteEvent();
                break;
            case 6:
                scheduler.getHighestPriority();
                break;
            case 7:
                scheduler.showStats();
                break;
            case 8:
                system("cls");
                cout << "\n================================" << endl;
                cout << "Thanks for using Event Scheduler!" << endl;
                cout << "================================" << endl;
                break;
            default:
                system("cls");
                cout << "\nInvalid choice! Please try again." << endl;
                system("pause");
        }
        
    } while (choice != 8);
    
    system("pause"); 
    return 0;
}
