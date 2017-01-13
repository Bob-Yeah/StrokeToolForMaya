#include <maya/MFnPlugin.h>
#include <maya/MArgList.h>
#include <maya/MObject.h>
#include <maya/MGlobal.h>

#include "CurveIKCmd.h"

//#define EXPORT _declspec(dllexport)

MStatus initializePlugin(MObject obj)
{
	MStatus   status = MStatus::kSuccess;
	MFnPlugin plugin(obj, "StrokeTool", "1.0", "Any");

	//register command
	status = plugin.registerCommand("CurveIKCmd", CurveIKCmd::creator);
	if (!status) {
		status.perror("registerCommand");
		return status;
	}
	MGlobal::executeCommand("source \"" + plugin.loadPath() + "/proc.mel\"");
	MGlobal::executeCommand("createMenu();");
	return status;
}

MStatus uninitializePlugin(MObject obj)
{
	MStatus   status = MStatus::kSuccess;
	MFnPlugin plugin(obj);

	//deregister command
	status = plugin.deregisterCommand("CurveIKCmd");
	if (!status) {
		status.perror("deregisterCommand");
		return status;
	}
	MGlobal::executeCommand("deleteMenu();");

	return status;
}