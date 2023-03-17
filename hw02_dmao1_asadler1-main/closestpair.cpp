#include "closestpair.h"
#include <algorithm>
#include <cstdlib>
#include <sys/time.h>  // used to seed srand for extra credit
#include <iostream>
#include <vector>

using namespace std;

Outcome brute(const vector<Point>& data) {
    Outcome best(data[0], data[1], distSquared(data[0],data[1]));
    for (unsigned int j=1; j < data.size(); j++) {
        for (unsigned int k=0; k < j; k++) {
            long long temp = distSquared(data[j], data[k]);
            if (temp < best.dsq) {
                best = Outcome(data[j], data[k], temp);
            }
        }
    }
    return best;
}
Outcome strip(vector <Point> strip,int size, Outcome d){
	
	long long min=d.dsq;
	Outcome result=d;
	for (int k=0;k<size;k++){
		for (int l = k+1; l < size && (strip[l].y - strip[l].y) < min; l++){
			if(distSquared(strip[l],strip[k]) < min){
				min=distSquared(strip[l],strip[k]);
				result= Outcome(strip[l],strip[k],min);
			}
		}

	}
	return result;



}
Outcome solve(const vector<Point>& dataX,vector<Point> dataY,int start,int stop){
	int size=stop-start;
	
	if(size<3)
	{
		Outcome result= Outcome(dataX[start],dataX[stop],distSquared(dataX[start],dataX[stop]));
		return result;
		
		
	}
	else
	{   
		Outcome result;

		
		int mid = size/2; // const or auto? some storage class not sure
		Point middle=dataX[mid]; //middle point
		vector<Point> dataSortYleft;
		vector<Point> dataSortYright;
		for (int g=0;g<dataY.size();g++){
			if (dataY[g].x>dataX[0].x && dataY[g].x<dataX[mid].x){
				dataSortYleft.push_back(dataY[g]);
			}

		}
		for (int g=0;g<dataY.size();g++){
			if (dataY[g].x>dataX[mid+1].x && dataY[g].x<dataX[stop].x){
				dataSortYright.push_back(dataY[g]);
			}

		}
		Outcome distanceL= solve(dataX,dataSortYleft,0,mid);
		Outcome distanceR= solve(dataX,dataSortYright,mid+1,size);
		
		// ^couldnt we just use this to cut down till 3?
		//split middle of array n/2 until 3 middle points to form strip	
		if(distanceL.dsq>distanceR.dsq){
			result=distanceR;
		}
		else {
			result=distanceL;
		}
		//strip is minimum of left and right subarray
		// ^ min does have a compare ability, should distanceSquared be used here?
		vector <Point> close; //array that contains close points
		int i=0;
		
		for (int j = 0; j < dataY.size(); j++){
			
			if (abs(dataY[j].x - middle.x) < result.dsq ){
				close.push_back(dataY[j]);
				i++;
			}
		}
	
		Outcome stripMin= strip(close,i,result);
		if(result.dsq>stripMin.dsq){
			result=stripMin;
		}
 
		
		
		return result;
	}
}
Outcome efficient(const vector<Point>& data) {
	
	//sort x and y
	vector<Point> datax(data);
	sort(datax.begin(),datax.end(), compareByX);// x left to right

	vector<Point> datay(data);
	sort(datay.begin(),datay.end(), compareByY);// x left to right

	
	return solve(datax,datay,0,data.size());
	
	
    
}

Outcome extra(const vector<Point>& data) {
    return Outcome();
}
