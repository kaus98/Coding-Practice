
bool isValid(int x, int y, int c1, vector<vector<int>> &image){
    return (x>=0 && x < image.size() && y >= 0 && y < image[0].size() && c1==image[x][y]);
}

void solve(vector<vector<int>> &image, int x, int y, int newColor, int originalColor){

    vector<int> mx{1,0,-1,0};
    vector<int> my{0,1,0,-1};

    image[x][y] = newColor;
    int  nx, ny;

    for(int i = 0; i < 4; i++){
        nx = x+mx[i];
        ny = y+my[i];

        if(isValid(nx, ny, originalColor, image)){
            solve(image, nx, ny, newColor, originalColor);
        }
    }

}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if(image[x][y] == newColor) return image;
    solve(image, x, y, newColor, image[x][y]);
    return image;
}