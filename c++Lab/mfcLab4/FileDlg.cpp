// FileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "mfcLab4.h"
#include "FileDlg.h"
#include "FileLoader.h"

// FileDlg dialog

IMPLEMENT_DYNAMIC(FileDlg, CDialog)

FileDlg::FileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(FileDlg::IDD, pParent)
{

}

FileDlg::~FileDlg()
{
}

void FileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(FileDlg, CDialog)
	ON_BN_CLICKED(IDC_OPENFILE, &FileDlg::OnBnClickedOpenfile)
	ON_BN_CLICKED(IDC_SELFILES, &FileDlg::OnBnClickedSelfiles)
END_MESSAGE_MAP()


// FileDlg message handlers

////�ݹ�����ļ�
void FileDlg::FindFiles(CTreeCtrl* m_Tree,HTREEITEM root,HTREEITEM parent,CString strPath,int deep){

	if(deep > 10){
		return;
	}
	 CString strWildcard(strPath);
     strWildcard += _T("\\*.*");
   CFileFind ff;
   BOOL bFind = ff.FindFile(strWildcard);

   while(bFind)
   {
      bFind = ff.FindNextFile();
      if (ff.IsDots() || ff.IsSystem() || ff.IsHidden())
         continue;
      
      if (ff.IsDirectory())
      {
		 CString dir = ff.GetFilePath();

		HTREEITEM currentNode;
		 if(parent==NULL){
		currentNode = m_Tree->InsertItem(dir,NULL,NULL,root);
		 }
		 else{
		currentNode = m_Tree->InsertItem(dir,NULL,NULL,parent);
		 }
		 this->FindFiles(m_Tree,root,currentNode,dir,++deep);

      }
      else
      {
         CString strFileName = ff.GetFileName();
		 if(parent==NULL){
		 m_Tree->InsertItem(strFileName,NULL,NULL,root);
		 }
		 else{
		 m_Tree->InsertItem(strFileName,NULL,NULL,parent);
		 }
		 
      }
   }
}

void FileDlg::OnBnClickedOpenfile()
{
	this->OpenFileDialog();
	
	// TODO: Add your control notification handler code here
}

////�Ի���====================================

////���ļ��Ի���
void FileDlg::OpenFileDialog(){

CFileDialog dlg(TRUE, NULL, NULL,
           OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
           NULL);

    if(dlg.DoModal() == IDOK)
    {
          CString szFilename = dlg.GetPathName();

CFile f;
f.Open(szFilename,CFile::modeReadWrite);
char* buf = new char[f.GetLength()];

f.Read(buf,f.GetLength());
f.Close();

CString s(buf);
GetDlgItem(IDC_EDIT1)->SetWindowTextW(s);
delete[] buf;

    }
}


////��Ŀ¼�Ի���
void FileDlg::OpenDirDialog(){
CString strP =_T("ѡ��Ŀ¼");  
	int length = 1024;

LPWSTR szPath = strP.GetBuffer(1024);

// do something with the string that pwsz points to.

strP.ReleaseBuffer();

    CString str;
    BROWSEINFO bi;   
    bi.hwndOwner = m_hWnd;   
    bi.pidlRoot = NULL;   
    bi.pszDisplayName = szPath;   
    bi.lpszTitle = _T("��ѡ��Ҫ������Ŀ¼��");   
    bi.ulFlags = 0;   
    bi.lpfn = NULL;   
    bi.lParam = 0;   
    bi.iImage = 0;   
    //����ѡ��Ŀ¼�Ի���
    LPITEMIDLIST lp = SHBrowseForFolder(&bi);  

    if(lp && SHGetPathFromIDList(lp,szPath))   
    {
		CTreeCtrl* m_Tree = (CTreeCtrl*)GetDlgItem(IDC_FILETREE);
	////������ʽ
m_Tree->ModifyStyle(NULL,TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT); 
HTREEITEM root = m_Tree->InsertItem(szPath,NULL,NULL);///root���ǽڵ�ı���
	
this->FindFiles(m_Tree,root,NULL,szPath,0);
    }
	else {
        AfxMessageBox(_T("��Ч��Ŀ¼��������ѡ��"));  
		
	}
}



//=======================================

void FileDlg::OnBnClickedSelfiles()
{
	this->OpenDirDialog();
	// TODO: Add your control notification handler code here
}
