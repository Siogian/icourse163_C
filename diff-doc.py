import os
import click
from win32com.client import Dispatch

def diff_doc(base_doc, new_doc):
    destination = None
    
    # Microsoft Office versions for Microsoft Windows OS
    ver_office_2000 = 9
    ver_office_2007 = 12
    ver_office_2013 = 15

    window_master_view = 5
    window_normal_view = 1
    window_outline_view = 2
    window_reading_view = 7
    # 相对路径下打开文件会抛出异常，将路径转换为绝对路径
    base_doc = os.path.abspath(base_doc)
    new_doc = os.path.abspath(new_doc)

    if not os.path.exists(base_doc):
        print("File " + base_doc + " does not exist. Cannot compare the documents.")
        os._exit(1)
    if not os.path.exists(new_doc):
        print("File " + new_doc + " does not exist. Cannot compare the documents.")
        os._exit(1)

    word = Dispatch("Word.Application")
    # disable macros
    word.AutomationSecurity = 3; # msoAutomationSecurityForceDisable

    if eval(word.Version) >= ver_office_2013:
        print(word.Version)

    if eval(word.Version) >= ver_office_2007:
        print(word.Version)

    word.visible = True

    # Open the new document
    try:
        destination = word.Documents.Open(new_doc, True, eval(word.Version) < ver_office_2013)
    except Exception as e:
        try:
            # Open empty document to prevent bug where first Open() call fails
            word.Documents.Add()
            destination = word.Documents.Open(new_doc, True, eval(word.Version) < ver_office_2013)
        except Exception as e:
            print("Error opening " + new_doc)
            os._exit(1)
    
    # If the Type property returns either wdOutlineView or wdMasterView and the Count property returns zero, the current document is an outline.
    if destination.ActiveWindow.View.Type == window_outline_view or (destination.ActiveWindow.View.Type == window_master_view or destination.ActiveWindow.View.Type == window_reading_view) and destination.Subdocuments.Count == 0:
        # Change the Type property of the current document to normal
        destination.ActiveWindow.View.Type = window_normal_view
    
    if eval(word.Version) <= ver_office_2000:
        pass
    else:
        # Compare for Office XP (2002) and later
        try:
            destination.Compare(sBaseDoc, "Comparison", wdCompareTargetNew, true, true);
        except Exception as e:
        {
            WScript.Echo("Error comparing " + sBaseDoc + " and " + sNewDoc);
            // Close the first document and quit
            destination.Close(wdDoNotSaveChanges);
            WScript.Quit(1);
        }
    print("Hello")


@click.command()
# in and out file
@click.argument('base_doc', required=True)
@click.argument('new_doc', required=True)
def diff_doc_cli(base_doc, new_doc):
    """
        python diff_doc.py base.doc[x] new.doc[x]
    \n"""
    diff_doc(base_doc, new_doc)
if __name__ == "__main__":
    diff_doc_cli()