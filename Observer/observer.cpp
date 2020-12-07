#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <string>

using namespace std;

class IObserver {
 public:
  virtual ~IObserver(){};
  virtual void Update(const string &message_from_subject) = 0;
};

class ISubject {
 public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

class Subject : public ISubject {
 public:
  virtual ~Subject() {
    cout << "Goodbye, I was the Subject. (I UPDATE AND ADD REMOVE USERS)\n";
  }

  void Attach(IObserver *observer) override {
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override {
    list_observer_.remove(observer);
  }
  void Notify() override {
    list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObserver();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(message_);
      ++iterator;
    }
  }

  void CreateMessage(std::string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManyObserver() {
    cout << "There are " << list_observer_.size() << " registered users.\n";
  }

 private:
  list<IObserver *> list_observer_;
  string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    cout << "Hello! Please enter name: "<<endl;
    cin >> username;
    this->subject_.Attach(this);
    cout << "Hello, "<< username << " (User \"" << ++Observer::static_number_ << "\").\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    cout << "Goodbye, "<< username << " (User \"" << this->number_ << "\").\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    cout << username <<" (User \"" << number_ << "\") has unregistered.\n";
  }
  void PrintInfo() {
    cout << username <<" (User \"" << this->number_ << "\"): you have a new message --> " << this->message_from_subject_ << "\n";
  }

 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  string username;
  int number_;
};
//string Observer::username;
int Observer::static_number_ = 0;

void ClientCode() {
  string response;
  string unregister;
  int userNumber;
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  while(1){
  cout<< "Do you want to add another user? (y/n)"<<endl;
  cin>>response;
  if (response == "y"){
  Observer *observer2 = new Observer(*subject);
  }
  else if (response == "n"){
  subject->CreateMessage("Leaderboard has updated.");
  break;
  }
  else {
  cout << "invalid" << endl;
  break;
  }
} 
  while(1){
  cout << "Would you like to remove a user? (y/n)" << endl;
  cin >> unregister;
  if (unregister == "y" || unregister == "yes"){
  cout << "which user? (enter user number)" << endl;
  cin >> userNumber;
  }
  if (userNumber == 1){
  observer1->RemoveMeFromTheList();
  delete observer1;
  delete subject;
  break;
  }
  else if (unregister == "n" || unregister == "no"){
  delete subject;
  break;
  }
}
}

int main() {
  ClientCode();
  return 0;
}
