#pragma once
//#include "vector.h"
//#include "matrix.h"
//#include <math.h>
//#include "global.h"
#include "stdlib.h"
//#include "Posture_Interp.h"
#include "Cartesian_line.h"
//#include "vld.h"
using namespace std;

int main(void)
{
	//double pp1[] = { 1,0,0,1400, 0,-1,0,-500, 0,0,-1,1000, 0,0,0,1 };
	//double pp2[] = { 0,0,1,1400, 0,-1,0,500, 1,0,0,1000, 0,0,0,1 };

	//double pp2[] = { 1,0,0,1400, 0,-1,0,500, 0,0,-1,1000, 0,0,0,1 };
	//double pp2[] = { 6.09264333073009e-17,-6.11303370722411e-18,0,1400, 0.0998334166468282,0.995004165278026,0,500, -0.995004165278026,0.0998334166468282,6.12323399573677e-17,1000, 0,0,0,1 };
	//matrix ppm1(4, 4, pp1);
	//matrix ppm2(4, 4, pp2);
	Posi_Pose PP1;//= Matrix2PP(ppm1);
	Posi_Pose PP2;//= Matrix2PP(ppm2);
	PP1.Posi = Vector(1400, -500, 1000);
	PP2.Posi = Vector(1400, 500, 1000);
	PP1.Pose = Quaternion(0.707106781186548,	0,	0.707106781186548,	0);
	PP2.Pose = Quaternion(0.707097942370197,	0.00353551917456039,	0.707097942370197,	0.00353551917456039);
	double tf = 2;
	double t_interval = 0.01;
	double v_percent = 0.5;

	
	Cartesian_Line Line1(PP1, PP2, cubic, speed, v_percent);

	ofstream outFile;

	outFile.open("D:\\Line1_posi.csv", ios::out);
	for (int i = 0; i <= Line1.Na; i++)
	{
		double t = i*t_interval;
		Line1.realtime(t);
		outFile << i + 1 << ',' << Line1.PP_n.Posi(1)<< ',' << Line1.PP_n.Posi(2) << ',' << Line1.PP_n.Posi(3)  << endl;
	}

	outFile.close();

	outFile.open("D:\\Line1_pose.csv", ios::out);
	for (int i = 0; i <= Line1.Na ; i++)
	{
		double t = i*t_interval;
		Line1.realtime(t);
		outFile << i + 1 << ',' << Line1.PP_n.Pose.w<< ',' << Line1.PP_n.Pose.x << ',' << Line1.PP_n.Pose.y << ',' << Line1.PP_n.Pose.z << endl;
	}

	outFile.close();

	outFile.open("D:\\Line1_VA.csv", ios::out);
	for (int i = 0; i <= Line1.Na ; i++)
	{
		double t = i*t_interval;
		Line1.realtime(t);
		outFile << i + 1 << ',' << Line1.V_n(1) << ',' << Line1.V_n(2) << ',' << Line1.V_n(3) << ',' << Line1.V_n(4) << ','  << Line1.V_n(5) << ',' << Line1.V_n(6)
			<< ',' << Line1.A_n(1) << ',' << Line1.A_n(2) << ',' << Line1.A_n(3) << ',' << Line1.A_n(4) << ',' << Line1.A_n(5) << ',' << Line1.A_n(6) << endl;
	}

	outFile.close();
}