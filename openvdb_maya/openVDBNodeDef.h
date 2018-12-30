#pragma once

#include <maya/MString.h>
#include <maya/MTypeId.h>
#include <maya/MPxData.h>
#include <maya/MPxNode.h>
#include <maya/MPxLocatorNode.h>
#include <openvdb_maya/OpenVDBUtil.h>

struct OpenVDBCopyNode : public MPxNode
{
	OpenVDBCopyNode() {}
	virtual ~OpenVDBCopyNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aVdbInputA;
	static MObject aVdbInputB;
	static MObject aVdbOutput;
	static MObject aVdbSelectedGridNamesA;
	static MObject aVdbSelectedGridNamesB;
};

struct OpenVDBFilterNode : public MPxNode
{
	OpenVDBFilterNode() {}
	virtual ~OpenVDBFilterNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aVdbInput;
	static MObject aVdbOutput;
	static MObject aVdbSelectedGridNames;
	static MObject aFilter;
	static MObject aRadius;
	static MObject aOffset;
	static MObject aIterations;
};

struct OpenVDBFromMayaFluidNode : public MPxNode
{
public:
	OpenVDBFromMayaFluidNode() {}
	virtual ~OpenVDBFromMayaFluidNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aFluidNodeName;
	static MObject aVdbOutput;

	static MObject aDensity;
	static MObject aDensityName;
	static MObject aTemperature;
	static MObject aTemperatureName;
	static MObject aPressure;
	static MObject aPressureName;
	static MObject aFuel;
	static MObject aFuelName;
	static MObject aFalloff;
	static MObject aFalloffName;
	static MObject aVelocity;
	static MObject aVelocityName;
	static MObject aColors;
	static MObject aColorsName;
	static MObject aCoordinates;
	static MObject aCoordinatesName;
	static MObject aTime;
};


struct OpenVDBFromPolygonsNode : public MPxNode
{
	OpenVDBFromPolygonsNode() {}
	virtual ~OpenVDBFromPolygonsNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aMeshInput;
	static MObject aVdbOutput;
	static MObject aExportDistanceGrid;
	static MObject aDistanceGridName;
	static MObject aExportDensityGrid;
	static MObject aDensityGridName;
	static MObject aVoxelSize;
	static MObject aExteriorBandWidth;
	static MObject aInteriorBandWidth;
	static MObject aFillInterior;
	static MObject aUnsignedDistanceField;
	static MObject aEstimatedGridResolution;
	static MObject aNodeInfo;
};

struct OpenVDBReadNode : public MPxNode
{
	OpenVDBReadNode() {}
	virtual ~OpenVDBReadNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();
	static MObject aVdbFilePath;
	static MObject aVdbOutput;
	static MTypeId id;
};


struct OpenVDBToPolygonsNode : public MPxNode
{
	OpenVDBToPolygonsNode() {};
	virtual ~OpenVDBToPolygonsNode() {};

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void * creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aVdbInput;
	static MObject aIsovalue;
	static MObject aAdaptivity;
	static MObject aVdbAllGridNames;
	static MObject aVdbSelectedGridNames;
	static MObject aMeshOutput;
};


struct OpenVDBTransformNode : public MPxNode
{
	OpenVDBTransformNode() {}
	virtual ~OpenVDBTransformNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();

	static MTypeId id;
	static MObject aVdbInput;
	static MObject aVdbOutput;
	static MObject aVdbSelectedGridNames;
	static MObject aTranslate;
	static MObject aRotate;
	static MObject aScale;
	static MObject aPivot;
	static MObject aUniformScale;
	static MObject aInvert;
};

namespace mvdb = openvdb_maya;

struct OpenVDBVisualizeNode : public MPxLocatorNode
{
	OpenVDBVisualizeNode();
	virtual ~OpenVDBVisualizeNode();

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	virtual void draw(M3dView & view, const MDagPath & path,
		M3dView::DisplayStyle style, M3dView::DisplayStatus status);

	virtual bool isBounded() const;
	virtual MBoundingBox boundingBox() const;

	static void * creator();
	static  MStatus initialize();

	static MObject aVdbInput;
	static MObject aVdbAllGridNames;
	static MObject aVdbSelectedGridNames;

	static MObject aVisualizeBBox;
	static MObject aVisualizeInternalNodes;
	static MObject aVisualizeLeafNodes;
	static MObject aVisualizeActiveTiles;
	static MObject aVisualizeActiveVoxels;
	static MObject aVisualizeSurface;
	static MObject aIsovalue;

	static MObject aCachedBBox;
	static MObject aCachedInternalNodes;
	static MObject aCachedLeafNodes;
	static MObject aCachedActiveTiles;
	static MObject aCachedActiveVoxels;
	static MObject aCachedSurface;


	static MTypeId id;

private:
	std::vector<mvdb::BufferObject> mBBoxBuffers;
	std::vector<mvdb::BufferObject> mNodeBuffers;
	std::vector<mvdb::BufferObject> mLeafBuffers;
	std::vector<mvdb::BufferObject> mTileBuffers;
	std::vector<mvdb::BufferObject> mSurfaceBuffers;
	std::vector<mvdb::BufferObject> mPointBuffers;

	mvdb::ShaderProgram mSurfaceShader, mPointShader;
	MBoundingBox mBBox;
};

struct OpenVDBWriteNode : public MPxNode
{
	OpenVDBWriteNode() {}
	virtual ~OpenVDBWriteNode() {}

	virtual MStatus compute(const MPlug& plug, MDataBlock& data);

	static void* creator();
	static MStatus initialize();
	static MObject aVdbFilePath;
	static MObject aVdbInput;
	static MObject aVdbOutput;
	static MTypeId id;
};
