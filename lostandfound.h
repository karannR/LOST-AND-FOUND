// lostandfound.h
// Core classes for the Lost and Found system.
// The GUI (mainwindow.cpp) uses this file.

#ifndef LOSTANDFOUND_H
#define LOSTANDFOUND_H

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

// ---------- Base class for any item ----------
class Item {
protected:
    std::string name;
    std::string category;
    std::string description;
    std::string date;
public:
    Item() {}
    Item(std::string n, std::string c, std::string d, std::string dt)
        : name(n), category(c), description(d), date(dt) {}

    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    std::string getDescription() const { return description; }
    std::string getDate() const { return date; }
};

// ---------- A found item (added by staff) ----------
class FoundItem : public Item {
    std::string locationFound;
public:
    FoundItem() {}
    FoundItem(std::string n, std::string c, std::string d,
              std::string dt, std::string loc)
        : Item(n, c, d, dt), locationFound(loc) {}
    std::string getLocation() const { return locationFound; }
};

// ---------- A lost report (added by student) ----------
class LostReport : public Item {
    std::string reportedBy;
    std::string contact;
public:
    LostReport() {}
    LostReport(std::string n, std::string c, std::string d, std::string dt,
               std::string by, std::string contactInfo)
        : Item(n, c, d, dt), reportedBy(by), contact(contactInfo) {}
    std::string getReportedBy() const { return reportedBy; }
    std::string getContact() const { return contact; }
};

// ---------- Helper functions ----------
std::string toLowerStr(std::string s);
int priorityScore(const std::string &category);

// ---------- The main center that manages everything ----------
class LostAndFoundCenter {
private:
    std::vector<FoundItem> allFoundItems;
    std::unordered_map<std::string, std::vector<int>> nameIndex;
    std::queue<LostReport> pendingReports;
    std::priority_queue<std::pair<int, int>> urgentQueue;

public:
    void addFoundItem(const FoundItem &item);
    void addLostReport(const LostReport &report);

    std::vector<FoundItem> searchFound(const std::string &query) const;

    bool processNextPendingReport(LostReport &outReport,
                                  std::vector<FoundItem> &outMatches);

    int pendingCount() const;
    std::vector<LostReport> peekPendingReports() const;
    std::vector<FoundItem> getAllFoundItemsSorted() const;
    std::vector<FoundItem> getUrgentItemsInOrder() const;
};

#endif
