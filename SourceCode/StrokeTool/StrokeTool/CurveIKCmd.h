#pragma once

#include <maya/MPxCommand.h>
#include <maya/MFnNurbsCurve.h>
#include <string>


class CurveIKCmd : public MPxCommand
{
private:
public:
	CurveIKCmd();
	virtual ~CurveIKCmd();
	static void* creator() { return new CurveIKCmd(); }
	MStatus doIt(const MArgList& args);
	static bool builtLocalSkeleton;
};

