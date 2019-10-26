/*
 * Copyright (c) 2003-2019 Rony Shapiro <ronys@pwsafe.org>.
 * All rights reserved. Use of the code is allowed under the
 * Artistic License 2.0 terms, as specified in the LICENSE file
 * distributed with this code, or available from
 * http://www.opensource.org/licenses/artistic-license-2.0.php
 */

/** \file SafeCombinationEntryDlg.h
 * 
 */

// Generated by DialogBlocks, Sun 18 Jan 2009 09:22:13 PM IST

#ifndef _SAFECOMBINATIONENTRYDLG_H_
#define _SAFECOMBINATIONENTRYDLG_H_

/*!
 * Includes
 */

////@begin includes
#include <wx/valgen.h>
////@end includes
#include "core/PWScore.h"
#ifndef NO_YUBI
#include "YubiMixin.h"
#endif

/*!
 * Forward declarations
 */

////@begin forward declarations
class SafeCombinationCtrl;
////@end forward declarations
class wxTimer;

/*!
 * Control identifiers
 */
#ifndef wxDIALOG_MODAL
#define wxDIALOG_MODAL 0
#endif

////@begin control identifiers
#define ID_SAFECOMBINATIONENTRYDLG 10000
#define ID_DBASECOMBOBOX 10002
#define ID_ELLIPSIS 10003
#define ID_COMBINATION 10004
#define ID_READONLY 10005
#define ID_SHOWCOMBINATION 10505
#define ID_NEWDB 10006
#define ID_YUBIBTN 10229
#define ID_YUBISTATUS 10230
#define SYMBOL_SAFECOMBINATIONENTRYDLG_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxDIALOG_MODAL|wxTAB_TRAVERSAL
#define SYMBOL_SAFECOMBINATIONENTRYDLG_TITLE _("Safe Combination Entry")
#define SYMBOL_SAFECOMBINATIONENTRYDLG_IDNAME ID_SAFECOMBINATIONENTRYDLG
#define SYMBOL_SAFECOMBINATIONENTRYDLG_SIZE wxSize(400, 300)
#define SYMBOL_SAFECOMBINATIONENTRYDLG_POSITION wxDefaultPosition
////@end control identifiers

/*!
 * SafeCombinationEntryDlg class declaration
 */

#ifndef NO_YUBI
class SafeCombinationEntryDlg : public wxDialog, private YubiMixin
#else
class SafeCombinationEntryDlg: public wxDialog
#endif
{
  DECLARE_CLASS( SafeCombinationEntryDlg )
  DECLARE_EVENT_TABLE()

public:
  /// Constructors
  SafeCombinationEntryDlg(PWScore &core);
  SafeCombinationEntryDlg(wxWindow* parent, PWScore &core,
                          wxWindowID id = SYMBOL_SAFECOMBINATIONENTRYDLG_IDNAME, const wxString& caption = SYMBOL_SAFECOMBINATIONENTRYDLG_TITLE, const wxPoint& pos = SYMBOL_SAFECOMBINATIONENTRYDLG_POSITION, const wxSize& size = SYMBOL_SAFECOMBINATIONENTRYDLG_SIZE, long style = SYMBOL_SAFECOMBINATIONENTRYDLG_STYLE );

  /// Creation
  bool Create( wxWindow* parent, wxWindowID id = SYMBOL_SAFECOMBINATIONENTRYDLG_IDNAME, const wxString& caption = SYMBOL_SAFECOMBINATIONENTRYDLG_TITLE, const wxPoint& pos = SYMBOL_SAFECOMBINATIONENTRYDLG_POSITION, const wxSize& size = SYMBOL_SAFECOMBINATIONENTRYDLG_SIZE, long style = SYMBOL_SAFECOMBINATIONENTRYDLG_STYLE );

  /// Destructor
  ~SafeCombinationEntryDlg();

  /// Initialises member variables
  void Init();

  /// Creates the controls and sizers
  void CreateControls();

  ////@begin SafeCombinationEntryDlg event handler declarations

  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_ELLIPSIS
  void OnEllipsisClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_READONLY
  void OnReadonlyClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_SHOWCOMBINATION
  void OnShowCombination( wxCommandEvent& event );

  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_NEWDB
  void OnNewDbClick( wxCommandEvent& event );

  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
  void OnOk( wxCommandEvent& event );

  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
  void OnCancel( wxCommandEvent& event );

////@end SafeCombinationEntryDlg event handler declarations

  /// wxEVT_ACTIVATE event handler to do post initialization
  void OnActivate( wxActivateEvent& event );

#ifndef NO_YUBI
  /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_YUBIBTN
  void OnYubibtnClick( wxCommandEvent& event );

  void OnPollingTimer(wxTimerEvent& timerEvent);
#endif

  /// combobox event handlers, to change the read-only checkbox accordingly
  void OnDBSelectionChange( wxCommandEvent& event );

////@begin SafeCombinationEntryDlg member function declarations

  StringX GetPassword() const { return m_password ; }
  void SetPassword(StringX value) { m_password = value ; }

  /// Retrieves bitmap resources
  wxBitmap GetBitmapResource( const wxString& name );

  /// Retrieves icon resources
  wxIcon GetIconResource( const wxString& name );
////@end SafeCombinationEntryDlg member function declarations

  /// Should we show tooltips?
  static bool ShowToolTips();

  wxStaticText* m_version;
  wxComboBox* m_filenameCB;
  SafeCombinationCtrl* m_combinationEntry;

#ifndef NO_YUBI
  wxBitmapButton* m_YubiBtn;
  wxStaticText* m_yubiStatusCtrl;
#endif

private:
  StringX m_password;
  wxString m_filename;
  bool m_readOnly;
  PWScore &m_core;
  unsigned m_tries;
  bool m_postInitDone;

#ifndef NO_YUBI
  wxTimer* m_pollingTimer; // for Yubi, but can't go into mixin :-(
  // Not strictly yubi, but refactored to work with it:
#endif
  void ProcessPhrase();
  void UpdateReadOnlyCheckbox();
  void UpdateNew(bool isRO);
};

#endif // _SAFECOMBINATIONENTRYDLG_H_
