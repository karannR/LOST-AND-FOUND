// lostandfound.cpp
// The actual logic. Same DSA concepts as before:
// hashing, queue, priority queue, sorting.

#include "lostandfound.h"
#include <algorithm>
#include <cctype>

// convert a string to lowercase
std::string toLowerStr(std::string s) {
    for (auto &c : s) c = std::tolower((unsigned char)c);
    return s;
}

// give a priority number to a category
// higher number = more urgent
int priorityScore(const std::string &category) {
    std::string c = toLowerStr(category);
    if (c == "id card" || c == "wallet" || c == "phone" || c == "laptop")
        return 3;
    if (c == "bag" || c == "keys")
        return 2;
    return 1;
}

// add a found item to the center
void LostAndFoundCenter::addFoundItem(const FoundItem &item) {
    allFoundItems.push_back(item);
    int idx = (int)allFoundItems.size() - 1;
    nameIndex[toLowerStr(item.getName())].push_back(idx);
    urgentQueue.push({priorityScore(item.getCategory()), idx});
}

// add a lost report to the pending queue
void LostAndFoundCenter::addLostReport(const LostReport &report) {
    pendingReports.push(report);
}

// search found items by name / category / description
std::vector<FoundItem> LostAndFoundCenter::searchFound(
        const std::string &query) const {
    std::vector<FoundItem> results;
    std::string q = toLowerStr(query);

    // first try exact name match from hash map (fast)
    auto it = nameIndex.find(q);
    if (it != nameIndex.end()) {
        for (int idx : it->second)
            results.push_back(allFoundItems[idx]);
    }

    // then also check every item for keyword match (slower but useful)
    for (const auto &item : allFoundItems) {
        bool already = false;
        for (const auto &r : results) {
            if (r.getName() == item.getName() && r.getDate() == item.getDate()) {
                already = true;
                break;
            }
        }
        if (already) continue;

        if (toLowerStr(item.getName()).find(q) != std::string::npos ||
            toLowerStr(item.getCategory()).find(q) != std::string::npos ||
            toLowerStr(item.getDescription()).find(q) != std::string::npos) {
            results.push_back(item);
        }
    }
    return results;
}

// take the next pending report and look for a match
bool LostAndFoundCenter::processNextPendingReport(
        LostReport &outReport, std::vector<FoundItem> &outMatches) {
    if (pendingReports.empty()) return false;
    outReport = pendingReports.front();
    pendingReports.pop();
    outMatches = searchFound(outReport.getName());
    return true;
}

int LostAndFoundCenter::pendingCount() const {
    return (int)pendingReports.size();
}

// give a copy of all pending reports (for display)
std::vector<LostReport> LostAndFoundCenter::peekPendingReports() const {
    std::vector<LostReport> copy;
    std::queue<LostReport> temp = pendingReports;
    while (!temp.empty()) {
        copy.push_back(temp.front());
        temp.pop();
    }
    return copy;
}

// return all found items sorted by date (newest first)
std::vector<FoundItem> LostAndFoundCenter::getAllFoundItemsSorted() const {
    std::vector<FoundItem> copy = allFoundItems;
    std::sort(copy.begin(), copy.end(),
              [](const FoundItem &a, const FoundItem &b) {
                  return a.getDate() > b.getDate();
              });
    return copy;
}

// return items in urgency order (using priority queue)
std::vector<FoundItem> LostAndFoundCenter::getUrgentItemsInOrder() const {
    std::vector<FoundItem> result;
    std::priority_queue<std::pair<int, int>> copy = urgentQueue;
    while (!copy.empty()) {
        result.push_back(allFoundItems[copy.top().second]);
        copy.pop();
    }
    return result;
}
