#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

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
    cout << "Goodbye, I was the Subject.\n";
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

  void CreateMessage(string message = "Empty") {
    this->message_ = message;
    Notify();
  }
  void HowManyObserver() {
    std::cout << "There are " << list_observer_.size() << " registered users.\n";
  }

 private:
  list<IObserver *> list_observer_;
  string message_;
};

class Observer : public IObserver {
 public:
  Observer(Subject &subject) : subject_(subject) {
    this->subject_.Attach(this);
    cout << "Hello, User \"" << ++Observer::static_number_ << "\".\n";
    this->number_ = Observer::static_number_;
  }
  virtual ~Observer() {
    cout << "Goodbye, User \"" << this->number_ << "\".\n";
  }

  void Update(const std::string &message_from_subject) override {
    message_from_subject_ = message_from_subject;
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    cout << "User \"" << number_ << "\" has unregistered.\n";
  }
  void PrintInfo() {
    cout << "User \"" << this->number_ << "\": you have a new message --> " << this->message_from_subject_ << "\n";
  }

 private:
  string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
  Subject *subject = new Subject;
  Observer *observer1 = new Observer(*subject);
  Observer *observer2 = new Observer(*subject);
  Observer *observer3 = new Observer(*subject);
  Observer *observer4;
  Observer *observer5;

  subject->CreateMessage("Leaderboard has updated.");
  observer3->RemoveMeFromTheList();

  subject->CreateMessage("A new test has been added to your count.");
  observer4 = new Observer(*subject);

  observer2->RemoveMeFromTheList();
  observer5 = new Observer(*subject);

  observer4->RemoveMeFromTheList();
  observer1->RemoveMeFromTheList();

  delete observer2;
  delete observer1;
  delete subject;
}

int main() {
  ClientCode();
  return 0;
}

#endif
