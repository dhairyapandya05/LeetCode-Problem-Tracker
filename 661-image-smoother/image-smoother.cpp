class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        int prevcorner = 0;
        vector<int> temp(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0, count = 0;
                if (i + 1 < n) {
                    if (j - 1 >= 0) {
                        sum += img[i + 1][j - 1]; // bottom left corner
                        count++;
                    }
                    sum += img[i + 1][j]; // bottom cell
                    count++;
                    if (j + 1 < m) {
                        sum += img[i + 1][j + 1]; // bottom right corner
                        count++;
                    }
                }
                if (j + 1 < m) {
                    sum += img[i][j + 1];
                    count++;
                }
                sum += img[i][j];
                count++;
                if (j - 1 >= 0) {
                    sum += temp[j - 1];
                    count++;
                }

                if (i - 1 >= 0) {
                    if (j - 1 >= 0) {
                        sum += prevcorner; // top left corner
                        count++;
                    }
                    sum += temp[j]; // top cell
                    count++;
                    if (j + 1 < m) {
                        sum += temp[j + 1]; // top right corner
                        count++;
                    }
                }
                if (i - 1 >= 0) {
                    prevcorner = temp[j];
                }
                temp[j] = img[i][j];
                img[i][j] = sum / count;
            }
        }

        return img;
    }
};
