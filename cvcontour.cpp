#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image,srcimage;
	srcimage	= imread(argv[1],CV_LOAD_IMAGE_UNCHANGED);
	cvtColor(srcimage,image, COLOR_BGR2GRAY);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);
	imshow("gray",image);

	GaussianBlur(image,image,Size(5,5),0);
	namedWindow("blur",CV_WINDOW_AUTOSIZE);
	imshow("blur",image);
	imwrite("blur.jpg",image);

	threshold(image,image,60,255,CV_THRESH_BINARY);
	namedWindow("thresh",CV_WINDOW_AUTOSIZE);
	imshow("thresh",image);
	imwrite("thresh.jpg",image);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(image, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);

	vector<Moments> mu(contours.size());
	for(int i=0;i<contours.size();i++)
	{
		mu[i] = moments( contours[i], false);
	}

	vector<Point2f> mc( contours.size());
	for(int i=0;i<contours.size();i++)
	{
		if(mu[i].m00 > 100) {
			mc[i] = Point2f(mu[i].m10/mu[i].m00, mu[i].m01/mu[i].m00);
	
			drawContours(srcimage, contours, i,(0,255,255,0),3);
			circle(srcimage, mc[i], 4, (255,255,255),-1,7,0);
		}
	}
	namedWindow("cont",CV_WINDOW_AUTOSIZE);
	imshow("cont",srcimage);
	imwrite("cont.jpg",srcimage);



	
	
	waitKey(0);
	return(0);
}
