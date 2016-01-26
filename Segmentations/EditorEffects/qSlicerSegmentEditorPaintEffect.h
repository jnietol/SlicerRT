/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

// .NAME qSlicerSegmentEditorPaintEffect - Logic class for segmentation handling
// .SECTION Description
// TODO

#ifndef __qSlicerSegmentEditorPaintEffect_h
#define __qSlicerSegmentEditorPaintEffect_h

// Segmentations Widgets includes
#include "qSlicerSegmentationsModuleWidgetsExport.h"

#include "qSlicerSegmentEditorLabelEffect.h"

class qSlicerSegmentEditorPaintEffectPrivate;
class vtkPolyData;

/// \ingroup SlicerRt_QtModules_Segmentations
class Q_SLICER_SEGMENTATIONS_EFFECTS_EXPORT qSlicerSegmentEditorPaintEffect :
  public qSlicerSegmentEditorLabelEffect
{
public:
  Q_OBJECT

public:
  typedef qSlicerSegmentEditorLabelEffect Superclass;
  qSlicerSegmentEditorPaintEffect(QObject* parent = NULL);
  virtual ~qSlicerSegmentEditorPaintEffect(); 

public:
  /// Get name of effect
  virtual QString name();

  /// Clone editor effect
  virtual qSlicerSegmentEditorAbstractEffect* clone();

  /// Get icon for effect to be displayed in segment editor
  virtual QIcon icon();

  /// Perform actions to deactivate the effect (such as destroy actors, etc.)
  virtual void deactivate();

  /// Callback function invoked when interaction happens
  /// \param callerInteractor Interactor object that was observed to catch the event
  /// \param eid Event identifier
  /// \param viewWidget Widget of the Slicer layout view. Can be \sa qMRMLSliceWidget or \sa qMRMLThreeDWidget
  virtual void processInteractionEvents(vtkRenderWindowInteractor* callerInteractor, unsigned long eid, qMRMLWidget* viewWidget);

  /// Update user interface from parameter set node
  virtual void updateGUIFromMRML(vtkObject* caller, void* callData);

  /// Update parameter set node from user interface
  virtual void updateMRMLFromGUI();

public:  
  /// Apply paint operation
  void apply();

protected:
  QScopedPointer<qSlicerSegmentEditorPaintEffectPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerSegmentEditorPaintEffect);
  Q_DISABLE_COPY(qSlicerSegmentEditorPaintEffect);
};

#endif