class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int arrSize = image.at(0).size();
        for (int i = 0; i<image.size(); i++){
            for (int n = 0; n<arrSize/2; n++){
                int temp = image.at(i).at(n);
                temp = temp==0 ? 1 : 0; 
                image.at(i).at(n) = image.at(i).at(arrSize-1-n);
                image.at(i).at(n) = image.at(i).at(n)==0 ? 1 : 0; 
                image.at(i).at(arrSize-1-n) = temp;
            }
            if (arrSize%2==1){
                image.at(i).at(arrSize/2) = image.at(i).at(arrSize/2)==0 ? 1 : 0; 
            }
        }

        return image;
    }
};
