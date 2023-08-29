#include "rviz_python_bindings/visualizer_frame_py.hpp"

using namespace rviz_common;

VisualizerFramePy::VisualizerFramePy(QWidget * parent)
: VisualizationFrame(rviz_common::ros_integration::RosNodeAbstractionIface::WeakPtr(), parent)
{
  ros_client_abstraction_ = std::make_unique<rviz_common::ros_integration::RosClientAbstraction>();
  rviz_ros_node_ = ros_client_abstraction_->init(0, nullptr, "rviz", false);
}

VisualizerFramePy::~VisualizerFramePy()
{
  ros_client_abstraction_->shutdown();
}

bool VisualizerFramePy::node_ok()
{
  return ros_client_abstraction_->ok();
}

void VisualizerFramePy::initialize(
  const QString & display_config_file)
{
  VisualizationFrame::initialize(rviz_ros_node_, display_config_file);
}
