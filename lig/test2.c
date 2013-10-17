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
static const char modulename[] = "lig/test2";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "#pragma DefaultVisibility=public",
  "method inline{}",
  "",
  "method constantProp1() is inline{",
  "    var a := 29 + 1",
  "    print(a)",
  "    var b := 9 - (a / 5);",
  "    var c ",
  "    c := b * 4",
  "    var d := true || false",
  "    d := true.orElse{false}",
  "    if(c > 10) then{",
  "        c := c - 10",
  "    }",
  "    return c * (60 / a)",
  "}",
  "",
  "method main(){",
  "    print(\"the answer is {constantProp1()}\")",
  "}",
  "",
  "main()",
  NULL
};
static Object strlit73;
static Object strlit84;
Object meth_lig_47_test2_inline0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
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
Object meth_lig_47_test2__apply28(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object self = *(getfromclosure(closure, 0));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object bool29 = alloc_Boolean(0);
// compilenode returning bool29
  gc_frame_end(frame);
  return bool29;
}
Object meth_lig_47_test2_constantProp11(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(5, NULL);
  pushclosure(NULL);
  pushstackframe(stackframe, "constantProp1");
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
  Object *var_a = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "a");
  Object *var_b = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "b");
  Object *var_c = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "c");
  Object *var_d = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "d");
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num3 = alloc_Float64(29);
// compilenode returning num3
  int op_slot_left_2 = gc_frame_newslot(num3);
  Object num4 = alloc_Float64(1);
// compilenode returning num4
  int op_slot_right_2 = gc_frame_newslot(num4);
  params[0] = num4;
  partcv[0] = 1;
  Object sum6 = callmethod(num3, "+", 1, partcv, params);
// compilenode returning sum6
  *var_a = sum6;
  if (sum6 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_a
  params[0] = *var_a;
  Object call7 = gracelib_print(NULL, 1,  params);
// compilenode returning call7
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num9 = alloc_Float64(9);
// compilenode returning num9
  int op_slot_left_8 = gc_frame_newslot(num9);
// compilenode returning *var_a
  int op_slot_left_10 = gc_frame_newslot(*var_a);
  Object num11 = alloc_Float64(5);
// compilenode returning num11
  int op_slot_right_10 = gc_frame_newslot(num11);
  params[0] = num11;
  partcv[0] = 1;
  Object quotient13 = callmethod(*var_a, "/", 1, partcv, params);
// compilenode returning quotient13
  int op_slot_right_8 = gc_frame_newslot(quotient13);
  params[0] = quotient13;
  partcv[0] = 1;
  Object diff15 = callmethod(num9, "-", 1, partcv, params);
// compilenode returning diff15
  *var_b = diff15;
  if (diff15 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_c = undefined;
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_b
  int op_slot_left_16 = gc_frame_newslot(*var_b);
  Object num17 = alloc_Float64(4);
// compilenode returning num17
  int op_slot_right_16 = gc_frame_newslot(num17);
  params[0] = num17;
  partcv[0] = 1;
  Object prod19 = callmethod(*var_b, "*", 1, partcv, params);
// compilenode returning prod19
  *var_c = prod19;
  if (prod19 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool22 = alloc_Boolean(1);
// compilenode returning bool22
  int op_slot_left_21 = gc_frame_newslot(bool22);
  Object bool23 = alloc_Boolean(0);
// compilenode returning bool23
  int op_slot_right_21 = gc_frame_newslot(bool23);
  params[0] = bool23;
  partcv[0] = 1;
  Object opresult25 = callmethod(bool22, "||", 1, partcv, params);
// compilenode returning opresult25
  *var_d = opresult25;
  if (opresult25 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe26 = gc_frame_new();
  Object block27 = alloc_Block(NULL, NULL, "lig/test2", 11);
  gc_frame_newslot(block27);
  block_savedest(block27);
  Object closure28 = createclosure(1, "_apply");
setclosureframe(closure28, stackframe);
  addtoclosure(closure28, selfslot);
  struct UserObject *uo28 = (struct UserObject*)block27;
  uo28->data[0] = (Object)closure28;
  Method *meth_meth_lig_47_test2__apply28 = addmethod2pos(block27, "_apply", &meth_lig_47_test2__apply28, 0);
int argcv_meth_lig_47_test2__apply28[] = {0};
meth_meth_lig_47_test2__apply28->type = alloc_MethodType(1, argcv_meth_lig_47_test2__apply28);
  meth_meth_lig_47_test2__apply28->definitionModule = modulename;
  meth_meth_lig_47_test2__apply28->definitionLine = 22;
// compilenode returning block27
  gc_frame_newslot(block27);
  Object bool31 = alloc_Boolean(1);
// compilenode returning bool31
  params[0] = block27;
  partcv[0] = 1;
  Object call32 = callmethod(bool31, "orElse",
    1, partcv, params);
  gc_frame_end(callframe26);
// compilenode returning call32
  *var_d = call32;
  if (call32 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_35 = gc_frame_newslot(*var_c);
  Object num36 = alloc_Float64(10);
// compilenode returning num36
  int op_slot_right_35 = gc_frame_newslot(num36);
  params[0] = num36;
  partcv[0] = 1;
  Object opresult38 = callmethod(*var_c, ">", 1, partcv, params);
// compilenode returning opresult38
  Object if34 = none;
  if (istrue(opresult38)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_39 = gc_frame_newslot(*var_c);
  Object num40 = alloc_Float64(10);
// compilenode returning num40
  int op_slot_right_39 = gc_frame_newslot(num40);
  params[0] = num40;
  partcv[0] = 1;
  Object diff42 = callmethod(*var_c, "-", 1, partcv, params);
// compilenode returning diff42
  *var_c = diff42;
  if (diff42 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if34 = none;
  } else {
  }
// compilenode returning if34
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 15
  setline(15);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_c
  int op_slot_left_44 = gc_frame_newslot(*var_c);
  Object num46 = alloc_Float64(60);
// compilenode returning num46
  int op_slot_left_45 = gc_frame_newslot(num46);
// compilenode returning *var_a
  int op_slot_right_45 = gc_frame_newslot(*var_a);
  params[0] = *var_a;
  partcv[0] = 1;
  Object quotient48 = callmethod(num46, "/", 1, partcv, params);
// compilenode returning quotient48
  int op_slot_right_44 = gc_frame_newslot(quotient48);
  params[0] = quotient48;
  partcv[0] = 1;
  Object prod50 = callmethod(*var_c, "*", 1, partcv, params);
// compilenode returning prod50
  return prod50;
// compilenode returning undefined
  gc_frame_end(frame);
  return undefined;
}
Object meth_lig_47_test2__apply61(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object self = *(getfromclosure(closure, 0));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object bool62 = alloc_Boolean(0);
// compilenode returning bool62
  gc_frame_end(frame);
  return bool62;
}
Object meth_lig_47_test2_main51(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct StackFrameObject *stackframe = alloc_StackFrame(5, NULL);
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
  Object *var_inlinedVar_0 = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "inlinedVar_0");
  Object *var_inlinedVar_1 = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "inlinedVar_1");
  Object *var_inlinedVar_2 = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "inlinedVar_2");
  Object *var_inlinedVar_3 = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "inlinedVar_3");
// Begin line 5
  setline(5);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num52 = alloc_Float64(30);
// compilenode returning num52
  *var_inlinedVar_0 = num52;
  if (num52 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num53 = alloc_Float64(30);
// compilenode returning num53
  params[0] = num53;
  Object call54 = gracelib_print(NULL, 1,  params);
// compilenode returning call54
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num55 = alloc_Float64(3);
// compilenode returning num55
  *var_inlinedVar_1 = num55;
  if (num55 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_inlinedVar_2 = undefined;
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num56 = alloc_Float64(12);
// compilenode returning num56
  *var_inlinedVar_2 = num56;
  if (num56 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool58 = alloc_Boolean(1);
// compilenode returning bool58
  *var_inlinedVar_3 = bool58;
  if (bool58 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 11
  setline(11);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe59 = gc_frame_new();
  Object block60 = alloc_Block(NULL, NULL, "lig/test2", 11);
  gc_frame_newslot(block60);
  block_savedest(block60);
  Object closure61 = createclosure(1, "_apply");
setclosureframe(closure61, stackframe);
  addtoclosure(closure61, selfslot);
  struct UserObject *uo61 = (struct UserObject*)block60;
  uo61->data[0] = (Object)closure61;
  Method *meth_meth_lig_47_test2__apply61 = addmethod2pos(block60, "_apply", &meth_lig_47_test2__apply61, 0);
int argcv_meth_lig_47_test2__apply61[] = {0};
meth_meth_lig_47_test2__apply61->type = alloc_MethodType(1, argcv_meth_lig_47_test2__apply61);
  meth_meth_lig_47_test2__apply61->definitionModule = modulename;
  meth_meth_lig_47_test2__apply61->definitionLine = 22;
// compilenode returning block60
  gc_frame_newslot(block60);
  Object bool64 = alloc_Boolean(1);
// compilenode returning bool64
  params[0] = block60;
  partcv[0] = 1;
  Object call65 = callmethod(bool64, "orElse",
    1, partcv, params);
  gc_frame_end(callframe59);
// compilenode returning call65
  *var_inlinedVar_3 = call65;
  if (call65 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object bool68 = alloc_Boolean(1);
// compilenode returning bool68
  Object if67 = none;
  if (istrue(bool68)) {
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num69 = alloc_Float64(2);
// compilenode returning num69
  *var_inlinedVar_2 = num69;
  if (num69 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
    gc_frame_newslot(none);
    if67 = none;
  } else {
  }
// compilenode returning if67
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit73 == NULL) {
    strlit73 = alloc_String("the answer is ");
    gc_root(strlit73);
  }
// compilenode returning strlit73
  int op_slot_left_72 = gc_frame_newslot(strlit73);
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_inlinedVar_2
  int op_slot_left_74 = gc_frame_newslot(*var_inlinedVar_2);
// Begin line 15
  setline(15);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num76 = alloc_Float64(60);
// compilenode returning num76
  int op_slot_left_75 = gc_frame_newslot(num76);
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num77 = alloc_Float64(30);
// compilenode returning num77
  int op_slot_right_75 = gc_frame_newslot(num77);
  params[0] = num77;
  partcv[0] = 1;
  Object quotient79 = callmethod(num76, "/", 1, partcv, params);
// compilenode returning quotient79
  int op_slot_right_74 = gc_frame_newslot(quotient79);
  params[0] = quotient79;
  partcv[0] = 1;
  Object prod81 = callmethod(*var_inlinedVar_2, "*", 1, partcv, params);
// compilenode returning prod81
  int op_slot_right_72 = gc_frame_newslot(prod81);
  params[0] = prod81;
  partcv[0] = 1;
  Object opresult83 = callmethod(strlit73, "++", 1, partcv, params);
// compilenode returning opresult83
  int op_slot_left_71 = gc_frame_newslot(opresult83);
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit84 == NULL) {
    strlit84 = alloc_String("");
    gc_root(strlit84);
  }
// compilenode returning strlit84
  int op_slot_right_71 = gc_frame_newslot(strlit84);
  params[0] = strlit84;
  partcv[0] = 1;
  Object opresult86 = callmethod(opresult83, "++", 1, partcv, params);
// compilenode returning opresult86
  params[0] = opresult86;
  Object call87 = gracelib_print(NULL, 1,  params);
// compilenode returning call87
  gc_frame_end(frame);
  return call87;
}
Object module_lig_47_test2_init() {
  int flags = 0;
  int frame = gc_frame_new();
  Object self = alloc_obj2(5, 5);
  gc_root(self);
  prelude = module_StandardPrelude_init();
  adddatum2(self, prelude, 0);
  addmethod2(self, "outer", &grace_userobj_outer);
  setline(1);
  setmodule(modulename);
  setsource(originalSourceLines);
  setclassname(self, "Module<lig/test2>");
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
  struct StackFrameObject *stackframe = alloc_StackFrame(5, NULL);
  gc_root((Object)stackframe);
  pushstackframe(stackframe, "module scope");
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object params[1];
  int partcv[1];
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_test2_inline0 = addmethod2pos(self, "inline", &meth_lig_47_test2_inline0, 1);
int argcv_meth_lig_47_test2_inline0[] = {0};
meth_meth_lig_47_test2_inline0->type = alloc_MethodType(1, argcv_meth_lig_47_test2_inline0);
  meth_meth_lig_47_test2_inline0->definitionModule = modulename;
  meth_meth_lig_47_test2_inline0->definitionLine = 2;
// compilenode returning 
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[2] = emptyclosure;
  Method *meth_meth_lig_47_test2_constantProp11 = addmethod2pos(self, "constantProp1", &meth_lig_47_test2_constantProp11, 2);
int argcv_meth_lig_47_test2_constantProp11[] = {0};
meth_meth_lig_47_test2_constantProp11->type = alloc_MethodType(1, argcv_meth_lig_47_test2_constantProp11);
  meth_meth_lig_47_test2_constantProp11->definitionModule = modulename;
  meth_meth_lig_47_test2_constantProp11->definitionLine = 4;
// compilenode returning 
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo51 = (struct UserObject*)self;
  uo51->data[3] = emptyclosure;
  Method *meth_meth_lig_47_test2_main51 = addmethod2pos(self, "main", &meth_lig_47_test2_main51, 3);
int argcv_meth_lig_47_test2_main51[] = {0};
meth_meth_lig_47_test2_main51->type = alloc_MethodType(1, argcv_meth_lig_47_test2_main51);
  meth_meth_lig_47_test2_main51->definitionModule = modulename;
  meth_meth_lig_47_test2_main51->definitionLine = 18;
// compilenode returning 
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe88 = gc_frame_new();
  partcv[0] = 0;
  Object call89 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe88);
// compilenode returning call89
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
  module_lig_47_test2_init();
  gracelib_stats();
  return 0;
}
