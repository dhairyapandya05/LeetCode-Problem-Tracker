class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int rightPanelty = 0;
        int leftPanelty = 0;

        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                rightPanelty++;
            }
        }
        int miniHr = 0;
        int totalPanelty;
        int minipanelty = rightPanelty;
        for (int i = 0; i < n; i++) {
            totalPanelty = rightPanelty + leftPanelty;
            if (totalPanelty < minipanelty) {
                minipanelty = totalPanelty;
                miniHr = i;
            }
            if (customers[i] == 'N') {
                leftPanelty++;
            } else if (customers[i] == 'Y') {
                rightPanelty--;
            }
        }
        if (leftPanelty < minipanelty) {
            miniHr = n;
        }
        return miniHr;
    }
};