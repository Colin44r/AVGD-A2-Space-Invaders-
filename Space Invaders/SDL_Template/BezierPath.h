#ifndef __BEZIERPATH_H
#define __BEZIERPATH_H
#include "MathHelper.h"
#include <vector>

using namespace SDLFramework;

class BezierPath {
private:
	std::vector<BezierCurve> mCurves;
	std::vector<int> mSamples;

public:
	BezierPath();
	~BezierPath();

	void AddCurve(BezierCurve curve, int samples);

	void Sample(std::vector<Vector2>* sampledPath);
};

#endif