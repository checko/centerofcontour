#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image;
	image	= imread(argv[1],CV_LOAD_IMAGE_UNCHANGED);
	cvtColor(image,image, COLOR_BGR2GRAY);
	namedWindow("gray", CV_WINDOW_AUTOSIZE);
	imshow("gray",image);

	GaussianBlur(image,image,Size(5,5),0);
	namedWindow("blur",CV_WINDOW_AUTOSIZE);
	imshow("blur",image);

	threshold(image,image,60,255,CV_THRESH_BINARY);
	namedWindow("thresh",CV_WINDOW_AUTOSIZE);
	imshow("thresh",image);
	
	
	waitKey(0);
	return(0);
}
