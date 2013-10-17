#include <gracelib.h>
#include <stdlib.h>
#ifndef __CYGWIN__
#pragma weak main
#endif
static char compilerRevision[] = "2f33f70cec8f2392593abe0f690fe1d68e938c1c";
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
static const char modulename[] = "lig/euler/euler_2";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "import \"mgcollections\" as col",
  "",
  "var sum := 0",
  "var a := 1",
  "var b := 1",
  "while{b < 4000000} do {",
  "    if((b % 2) == 0) then { sum := sum + b }",
  "    var tmp := b",
  "    b := a + b",
  "    a := tmp",
  "}",
  "",
  "print(sum)",
  NULL
};
Object module_mgcollections;
Object module_mgcollections_init();
Object meth_lig_47_euler_47_euler_2_sum1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 1, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "sum");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_sum = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_sum
  gc_frame_end(frame);
  return *var_sum;
}
Object meth_lig_47_euler_47_euler_2_sum_58__61_2(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 2, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "sum:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_sum = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var__var_assign_tmp = &(stackframe->slots[0]);
  *var__var_assign_tmp = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var__var_assign_tmp
  *var_sum = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_euler_47_euler_2_a5(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 3, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "a");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_a = getfromclosure(closure, 0);
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
// compilenode returning *var_a
  gc_frame_end(frame);
  return *var_a;
}
Object meth_lig_47_euler_47_euler_2_a_58__61_6(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 4, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "a:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_a = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var__var_assign_tmp = &(stackframe->slots[0]);
  *var__var_assign_tmp = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var__var_assign_tmp
  *var_a = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_euler_47_euler_2_b9(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 5, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "b");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  gc_frame_end(frame);
  return *var_b;
}
Object meth_lig_47_euler_47_euler_2_b_58__61_10(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 6, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "b:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var__var_assign_tmp = &(stackframe->slots[0]);
  *var__var_assign_tmp = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var__var_assign_tmp
  *var_b = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_euler_47_euler_2__apply14(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object self = *(getfromclosure(closure, 1));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// compilenode returning *var_b
  int op_slot_left_15 = gc_frame_newslot(*var_b);
  Object num16 = alloc_Float64(4000000);
// compilenode returning num16
  int op_slot_right_15 = gc_frame_newslot(num16);
  params[0] = num16;
  partcv[0] = 1;
  Object opresult18 = callmethod(*var_b, "<", 1, partcv, params);
// compilenode returning opresult18
  gc_frame_end(frame);
  return opresult18;
}
Object meth_lig_47_euler_47_euler_2__apply21(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_b = getfromclosure(closure, 0);
  Object *var_sum = getfromclosure(closure, 1);
  Object *var_a = getfromclosure(closure, 2);
  Object self = *(getfromclosure(closure, 3));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_tmp = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "tmp");
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  int op_slot_left_24 = gc_frame_newslot(*var_b);
  Object num25 = alloc_Float64(2);
// compilenode returning num25
  int op_slot_right_24 = gc_frame_newslot(num25);
  params[0] = num25;
  partcv[0] = 1;
  Object modulus27 = callmethod(*var_b, "%", 1, partcv, params);
// compilenode returning modulus27
  int op_slot_left_23 = gc_frame_newslot(modulus27);
  Object num28 = alloc_Float64(0);
// compilenode returning num28
  int op_slot_right_23 = gc_frame_newslot(num28);
  params[0] = num28;
  partcv[0] = 1;
  Object opresult30 = callmethod(modulus27, "==", 1, partcv, params);
// compilenode returning opresult30
  Object if22 = none;
  if (istrue(opresult30)) {
// compilenode returning *var_sum
  int op_slot_left_31 = gc_frame_newslot(*var_sum);
// compilenode returning *var_b
  int op_slot_right_31 = gc_frame_newslot(*var_b);
  params[0] = *var_b;
  partcv[0] = 1;
  Object sum33 = callmethod(*var_sum, "+", 1, partcv, params);
// compilenode returning sum33
  *var_sum = sum33;
  if (sum33 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if22 = none;
  } else {
  }
// compilenode returning if22
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  *var_tmp = *var_b;
  if (*var_b == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  int op_slot_left_35 = gc_frame_newslot(*var_a);
// compilenode returning *var_b
  int op_slot_right_35 = gc_frame_newslot(*var_b);
  params[0] = *var_b;
  partcv[0] = 1;
  Object sum37 = callmethod(*var_a, "+", 1, partcv, params);
// compilenode returning sum37
  *var_b = sum37;
  if (sum37 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_tmp
  *var_a = *var_tmp;
  if (*var_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object module_lig_47_euler_47_euler_2_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(8, 8);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/euler/euler_2>");
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
  struct StackFrameObject *stackframe = alloc_StackFrame(8, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[2];
  int partcv[2];
Object *var_col = alloc_var();
  Object *var_sum = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "sum");
  Object *var_a = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "a");
  Object *var_b = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "b");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
// Import of mgcollections as col
  if (module_mgcollections == NULL)
    module_mgcollections = module_mgcollections_init();
  *var_col = module_mgcollections;
// compilenode returning none
  Object num0 = alloc_Float64(0);
// compilenode returning num0
  *var_sum = num0;
  if (num0 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure1 = createclosure(1, "sum");
setclosureframe(closure1, stackframe);
  addtoclosure(closure1, var_sum);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[1] = (Object)closure1;
  Method *meth_meth_lig_47_euler_47_euler_2_sum1 = addmethod2pos(self, "sum", &meth_lig_47_euler_47_euler_2_sum1, 1);
int argcv_meth_lig_47_euler_47_euler_2_sum1[] = {0};
meth_meth_lig_47_euler_47_euler_2_sum1->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_sum1);
  meth_meth_lig_47_euler_47_euler_2_sum1->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_sum1->definitionLine = 13;
// compilenode returning 
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure2 = createclosure(1, "sum:=");
setclosureframe(closure2, stackframe);
  addtoclosure(closure2, var_sum);
  struct UserObject *uo2 = (struct UserObject*)self;
  uo2->data[2] = (Object)closure2;
  Method *meth_meth_lig_47_euler_47_euler_2_sum_58__61_2 = addmethod2pos(self, "sum:=", &meth_lig_47_euler_47_euler_2_sum_58__61_2, 2);
int argcv_meth_lig_47_euler_47_euler_2_sum_58__61_2[] = {1};
meth_meth_lig_47_euler_47_euler_2_sum_58__61_2->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_sum_58__61_2);
  meth_meth_lig_47_euler_47_euler_2_sum_58__61_2->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_sum_58__61_2->definitionLine = 13;
// compilenode returning 
// compilenode returning none
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num4 = alloc_Float64(1);
// compilenode returning num4
  *var_a = num4;
  if (num4 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure5 = createclosure(1, "a");
setclosureframe(closure5, stackframe);
  addtoclosure(closure5, var_a);
  struct UserObject *uo5 = (struct UserObject*)self;
  uo5->data[3] = (Object)closure5;
  Method *meth_meth_lig_47_euler_47_euler_2_a5 = addmethod2pos(self, "a", &meth_lig_47_euler_47_euler_2_a5, 3);
int argcv_meth_lig_47_euler_47_euler_2_a5[] = {0};
meth_meth_lig_47_euler_47_euler_2_a5->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_a5);
  meth_meth_lig_47_euler_47_euler_2_a5->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_a5->definitionLine = 13;
// compilenode returning 
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure6 = createclosure(1, "a:=");
setclosureframe(closure6, stackframe);
  addtoclosure(closure6, var_a);
  struct UserObject *uo6 = (struct UserObject*)self;
  uo6->data[4] = (Object)closure6;
  Method *meth_meth_lig_47_euler_47_euler_2_a_58__61_6 = addmethod2pos(self, "a:=", &meth_lig_47_euler_47_euler_2_a_58__61_6, 4);
int argcv_meth_lig_47_euler_47_euler_2_a_58__61_6[] = {1};
meth_meth_lig_47_euler_47_euler_2_a_58__61_6->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_a_58__61_6);
  meth_meth_lig_47_euler_47_euler_2_a_58__61_6->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_a_58__61_6->definitionLine = 13;
// compilenode returning 
// compilenode returning none
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num8 = alloc_Float64(1);
// compilenode returning num8
  *var_b = num8;
  if (num8 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure9 = createclosure(1, "b");
setclosureframe(closure9, stackframe);
  addtoclosure(closure9, var_b);
  struct UserObject *uo9 = (struct UserObject*)self;
  uo9->data[5] = (Object)closure9;
  Method *meth_meth_lig_47_euler_47_euler_2_b9 = addmethod2pos(self, "b", &meth_lig_47_euler_47_euler_2_b9, 5);
int argcv_meth_lig_47_euler_47_euler_2_b9[] = {0};
meth_meth_lig_47_euler_47_euler_2_b9->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_b9);
  meth_meth_lig_47_euler_47_euler_2_b9->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_b9->definitionLine = 13;
// compilenode returning 
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure10 = createclosure(1, "b:=");
setclosureframe(closure10, stackframe);
  addtoclosure(closure10, var_b);
  struct UserObject *uo10 = (struct UserObject*)self;
  uo10->data[6] = (Object)closure10;
  Method *meth_meth_lig_47_euler_47_euler_2_b_58__61_10 = addmethod2pos(self, "b:=", &meth_lig_47_euler_47_euler_2_b_58__61_10, 6);
int argcv_meth_lig_47_euler_47_euler_2_b_58__61_10[] = {1};
meth_meth_lig_47_euler_47_euler_2_b_58__61_10->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2_b_58__61_10);
  meth_meth_lig_47_euler_47_euler_2_b_58__61_10->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2_b_58__61_10->definitionLine = 13;
// compilenode returning 
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe12 = gc_frame_new();
  Object block13 = alloc_Block(NULL, NULL, "lig/euler/euler_2", 6);
  gc_frame_newslot(block13);
  block_savedest(block13);
  Object closure14 = createclosure(2, "_apply");
setclosureframe(closure14, stackframe);
  addtoclosure(closure14, var_b);
  addtoclosure(closure14, selfslot);
  struct UserObject *uo14 = (struct UserObject*)block13;
  uo14->data[0] = (Object)closure14;
  Method *meth_meth_lig_47_euler_47_euler_2__apply14 = addmethod2pos(block13, "_apply", &meth_lig_47_euler_47_euler_2__apply14, 0);
int argcv_meth_lig_47_euler_47_euler_2__apply14[] = {0};
meth_meth_lig_47_euler_47_euler_2__apply14->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2__apply14);
  meth_meth_lig_47_euler_47_euler_2__apply14->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2__apply14->definitionLine = 13;
// compilenode returning block13
  gc_frame_newslot(block13);
  Object block20 = alloc_Block(NULL, NULL, "lig/euler/euler_2", 6);
  gc_frame_newslot(block20);
  block_savedest(block20);
  Object closure21 = createclosure(4, "_apply");
setclosureframe(closure21, stackframe);
  addtoclosure(closure21, var_b);
  addtoclosure(closure21, var_sum);
  addtoclosure(closure21, var_a);
  addtoclosure(closure21, selfslot);
  struct UserObject *uo21 = (struct UserObject*)block20;
  uo21->data[0] = (Object)closure21;
  Method *meth_meth_lig_47_euler_47_euler_2__apply21 = addmethod2pos(block20, "_apply", &meth_lig_47_euler_47_euler_2__apply21, 0);
int argcv_meth_lig_47_euler_47_euler_2__apply21[] = {0};
meth_meth_lig_47_euler_47_euler_2__apply21->type = alloc_MethodType(1, argcv_meth_lig_47_euler_47_euler_2__apply21);
  meth_meth_lig_47_euler_47_euler_2__apply21->definitionModule = modulename;
  meth_meth_lig_47_euler_47_euler_2__apply21->definitionLine = 13;
// compilenode returning block20
  gc_frame_newslot(block20);
  params[0] = block13;
  params[1] = block20;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call41 = callmethodflags(prelude, "while()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe12);
// compilenode returning call41
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_sum
  params[0] = *var_sum;
  Object call42 = gracelib_print(NULL, 1,  params);
// compilenode returning call42
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
  module_lig_47_euler_47_euler_2_init();
  gracelib_stats();
  return 0;
}
