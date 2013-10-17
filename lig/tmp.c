#include <gracelib.h>
#include <stdlib.h>
#ifndef __CYGWIN__
#pragma weak main
#endif
static char compilerRevision[] = "a6a8af007b1e2c10caf60ddcfdcc155e846f9f82";
static Object undefined;
extern Object none;
extern Object _prelude;
extern Object String;
extern Object Number;
extern Object Boolean;
extern Object Dynamic;
extern Object Block;
extern Object None;
extern Object Type;
extern Object sourceObject;
static Object type_String;
static Object type_Number;
static Object type_Boolean;
static Object type_Block;
static Object type_None;
static Object type_Void;
static Object argv;
static Object emptyclosure;
static Object prelude;
static const char modulename[] = "lig/tmp";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "method inline{}",
  "",
  "method main is inline{",
  "    print(\"helloworld\")",
  "}",
  "",
  "main()",
  NULL
};
static Object strlit3;
Object meth_lig_47_tmp_inline1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(1, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "inline");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_tmp_main2(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(1, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit3 == NULL) {
    strlit3 = alloc_String("helloworld");
    gc_root(strlit3);
  }
// compilenode returning strlit3
  params[0] = strlit3;
  Object call4 = gracelib_print(NULL, 1,  params);
// compilenode returning call4
  gc_frame_end(frame);
  return call4;
}
Object meth_lig_47_tmp_mainmain0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(1, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "mainmain");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 1
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[1] = emptyclosure;
  Method *meth_meth_lig_47_tmp_inline1 = addmethod2pos(self, "inline", &meth_lig_47_tmp_inline1, 1);
int argcv_meth_lig_47_tmp_inline1[] = {0};
meth_meth_lig_47_tmp_inline1->type = alloc_MethodType(1, argcv_meth_lig_47_tmp_inline1);
  meth_meth_lig_47_tmp_inline1->definitionModule = modulename;
  meth_meth_lig_47_tmp_inline1->definitionLine = 1;
// compilenode returning 
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo2 = (struct UserObject*)self;
  uo2->data[2] = emptyclosure;
  Method *meth_meth_lig_47_tmp_main2 = addmethod2pos(self, "main", &meth_lig_47_tmp_main2, 2);
int argcv_meth_lig_47_tmp_main2[] = {0};
meth_meth_lig_47_tmp_main2->type = alloc_MethodType(1, argcv_meth_lig_47_tmp_main2);
  meth_meth_lig_47_tmp_main2->definitionModule = modulename;
  meth_meth_lig_47_tmp_main2->definitionLine = 3;
// compilenode returning 
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe5 = gc_frame_new();
  partcv[0] = 0;
  Object call6 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe5);
// compilenode returning call6
  gc_frame_end(frame);
  return call6;
}
Object module_lig_47_tmp_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(3, 3);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/tmp>");
  Object *var_MatchFailed = alloc_var();
  *var_MatchFailed = alloc_MatchFailed();
  Object *var_noSuchValue = alloc_var();
  *var_noSuchValue = none;
  Object *var_done = alloc_var();
  *var_done = none;
  Object *var_nothing = alloc_var();
  *var_nothing = none;
  Object *var_String = alloc_var();
  *var_String = String;
  type_String = String;
  Object *var_Block = alloc_var();
  *var_Block = Block;
  type_Block = Block;
  Object *var_Void = alloc_var();
  *var_Void = None;
  type_Void = None;
  Object *var_None = alloc_var();
  *var_None = None;
  type_None = None;
  Object *var_Number = alloc_var();
  *var_Number = Number;
  type_Number = Number;
  Object *var_Boolean = alloc_var();
  *var_Boolean = Boolean;
  type_Boolean = Boolean;
  Object *var_Dynamic = alloc_var();
  *var_Dynamic = Dynamic;
  Object *var_Type = alloc_var();
  *var_Type = Type;
  Object *var__prelude = alloc_var();
  *var__prelude = grace_prelude();
  gc_root(*var_MatchFailed);
  emptyclosure = createclosure(0, "empty");
  gc_root(emptyclosure);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[1];
  int partcv[1];
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_tmp_mainmain0 = addmethod2pos(self, "mainmain", &meth_lig_47_tmp_mainmain0, 1);
int argcv_meth_lig_47_tmp_mainmain0[] = {0};
meth_meth_lig_47_tmp_mainmain0->type = alloc_MethodType(1, argcv_meth_lig_47_tmp_mainmain0);
  meth_meth_lig_47_tmp_mainmain0->definitionModule = modulename;
  meth_meth_lig_47_tmp_mainmain0->definitionLine = 7;
// compilenode returning 
  int callframe7 = gc_frame_new();
  partcv[0] = 0;
  Object call8 = callmethodflags(self, "mainmain", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe7);
// compilenode returning call8
  gc_frame_end(frame);
  return self;
}
int main(int argc, char **argv) {
  initprofiling();
  setCompilerModulePath("/home/ligands/git/minigrace");
  gracelib_argv(argv);
  Object params[1];
  undefined = alloc_Undefined();
  none = alloc_none();
  Object tmp_argv = alloc_List();
  gc_root(tmp_argv);
  int partcv_push[] = {1};
  int i; for (i=0; i<argc; i++) {
    params[0] = alloc_String(argv[i]);
    callmethod(tmp_argv, "push", 1, partcv_push, params);
  }
  module_sys_init_argv(tmp_argv);
  module_lig_47_tmp_init();
  gracelib_stats();
  return 0;
}
