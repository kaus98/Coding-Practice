

double Y(double x, int &a, int &b, int &c){
	return -(a*x + c)/b;
}

double distance(double x1, double x2, double y1, double y2){
	return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double totalSum(vector<vector<int>> &dp, double x, int &a, int &b, int &c){

	double  y = Y(x, a, b, c);
	double dt = 0;

	for(auto point: dp) dt += distance(x, point[0], y, point[1]);
	return dt;
}


double optimumDistance(int a, int b, int c, vector<vector<int>> &points, int n){
	// Write your code here
	double start = -1000;
	double end = 1000;
	double diff = 1e-6;

	while(end-start > diff){

		double m1 = start + (end-start)/3;
		double m2 = end - (end-start)/3;

		double fm1 = totalSum(points, m1, a, b, c);
		double fm2 = totalSum(points, m2, a, b, c);

		if(fm1 > fm2) start = m1;
		else if(fm1 < fm2) end = m2;
		else {
			start = m1;
			end = m2;
		}
	}

	double x = (start+end)/2;
	return totalSum(points, x, a, b, c);
}
