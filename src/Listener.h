#pragma once
#include <tisudshl.h>
#include <opencv2/core.hpp>

using namespace cv;

const GUID media_guid = DShowLib::MEDIASUBTYPE_Y800;

class Listener :
    public  DShowLib::FrameNotificationSinkListener
{
private:
	Mat m_output;

public:
	bool flag = false;

public:
	virtual void sinkConnected(const DShowLib::FrameTypeInfo& frameType)
	{
		// We know this to be true since the sink is created as RGB24 below
		assert(frameType.subtype == media_guid);

		// Allocate temporary images once we know the size of image we will receive
		m_output.create(frameType.dim.cy, frameType.dim.cx, CV_8UC1);
	}
	virtual void sinkDisconnected()
	{
		// Release temporary images
		m_output.release();
	}
	virtual void frameReceived(DShowLib::IFrame& frame)
	{
		DShowLib::FrameTypeInfo ft = frame.getFrameType();

		// We know this to be true since the sink is created as RGB24 below
		assert(ft.subtype == media_guid);

		// We know these to be true since m_output was created with the frame type passed to sinkConnected
		assert(ft.dim.cx == m_output.cols);
		assert(ft.dim.cy == m_output.rows);

		m_output = Mat(ft.dim.cy, ft.dim.cx, CV_8UC1, frame.getPtr());

		this->frameFlag();
	}

	void frameFlag()
	{
		flag = true;
		return;
	}

	virtual Mat giveFrame()
	{
		return m_output;
	}
};