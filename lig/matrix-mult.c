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
static const char modulename[] = "lig/matrix-mult";
Object module_StandardPrelude_init();
static char *originalSourceLines[] = {
  "import \"sys\" as sys",
  "def width : Number = 75",
  "method inline{}",
  "method initAr() {",
  "    var ar := 1..width",
  "    var tmp := 1..width",
  "    for (tmp) do { v ->",
  "        ar[v] := tmp",
  "    }",
  "    ar",
  "}",
  "var avg := 0",
  "method main(n){",
  "    var time := sys.cputime",
  "    def A = initAr",
  "    def B = initAr",
  "    var sum : Number",
  "    var C := initAr",
  "    for(1..width) do { i->",
  "        for(1..width) do { j->",
  "            sum := 0",
  "            for(1..width) do { k->",
  "                sum := sum + (A[i][k] * B[k][j])",
  "            }",
  "            C[i][j] := sum",
  "        }",
  "    }",
  "    var tt := (sys.cputime - time)",
  "    avg := avg + tt",
  "    print(\"Run {n}: {tt}s\")",
  "}",
  "for(1..15) do { i ->",
  "    main(i)",
  "}",
  "print(\"average : {avg/15}s\")",
  NULL
};
static Object strlit82;
static Object strlit85;
static Object strlit90;
Object module_sys;
Object module_sys_init();
static Object strlit114;
static Object strlit121;
Object meth_lig_47_matrix_45_mult_inline0(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
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
Object meth_lig_47_matrix_45_mult__apply12(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[1];
  Object *var_tmp = getfromclosure(closure, 0);
  Object *var_ar = getfromclosure(closure, 1);
  Object self = *(getfromclosure(closure, 2));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_v = &(stackframe->slots[0]);
  *var_v = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 9
  setline(9);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe13 = gc_frame_new();
// Begin line 8
  setline(8);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_v
  gc_frame_newslot(*var_v);
// compilenode returning *var_tmp
  gc_frame_newslot(*var_tmp);
// compilenode returning *var_ar
  params[0] = *var_v;
  params[1] = *var_tmp;
  partcv[0] = 2;
  Object call14 = callmethod(*var_ar, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe13);
// compilenode returning call14
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_matrix_45_mult_initAr1(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 2, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(3, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "initAr");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[2];
  int partcv[2];
  Object *var_width = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_ar = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "ar");
  Object *var_tmp = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "tmp");
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
  Object num3 = alloc_Float64(1);
// compilenode returning num3
  int op_slot_left_2 = gc_frame_newslot(num3);
// compilenode returning *var_width
  int op_slot_right_2 = gc_frame_newslot(*var_width);
  params[0] = *var_width;
  partcv[0] = 1;
  Object opresult5 = callmethod(num3, "..", 1, partcv, params);
// compilenode returning opresult5
  *var_ar = opresult5;
  if (opresult5 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 6
  setline(6);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num7 = alloc_Float64(1);
// compilenode returning num7
  int op_slot_left_6 = gc_frame_newslot(num7);
// compilenode returning *var_width
  int op_slot_right_6 = gc_frame_newslot(*var_width);
  params[0] = *var_width;
  partcv[0] = 1;
  Object opresult9 = callmethod(num7, "..", 1, partcv, params);
// compilenode returning opresult9
  *var_tmp = opresult9;
  if (opresult9 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 7
  setline(7);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe10 = gc_frame_new();
// compilenode returning *var_tmp
  gc_frame_newslot(*var_tmp);
  Object block11 = alloc_Block(NULL, NULL, "lig/matrix-mult", 7);
  gc_frame_newslot(block11);
  block_savedest(block11);
  Object closure12 = createclosure(3, "_apply");
setclosureframe(closure12, stackframe);
  addtoclosure(closure12, var_tmp);
  addtoclosure(closure12, var_ar);
  addtoclosure(closure12, selfslot);
  struct UserObject *uo12 = (struct UserObject*)block11;
  uo12->data[0] = (Object)closure12;
  Method *meth_meth_lig_47_matrix_45_mult__apply12 = addmethod2pos(block11, "_apply", &meth_lig_47_matrix_45_mult__apply12, 0);
int argcv_meth_lig_47_matrix_45_mult__apply12[] = {1};
meth_meth_lig_47_matrix_45_mult__apply12->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult__apply12);
  meth_meth_lig_47_matrix_45_mult__apply12->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult__apply12->definitionLine = 35;
// compilenode returning block11
  gc_frame_newslot(block11);
  params[0] = *var_tmp;
  params[1] = block11;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call16 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe10);
// compilenode returning call16
// Begin line 10
  setline(10);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_ar
  gc_frame_end(frame);
  return *var_ar;
}
Object meth_lig_47_matrix_45_mult__apply48(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_sum = getfromclosure(closure, 0);
  Object *var_A = getfromclosure(closure, 1);
  Object *var_i = getfromclosure(closure, 2);
  Object *var_B = getfromclosure(closure, 3);
  Object *var_j = getfromclosure(closure, 4);
  Object self = *(getfromclosure(closure, 5));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_k = &(stackframe->slots[0]);
  *var_k = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 24
  setline(24);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 23
  setline(23);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_sum
  int op_slot_left_49 = gc_frame_newslot(*var_sum);
// compilenode returning *var_A
// compilenode returning *var_i
  params[0] = *var_i;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres51 = callmethod(*var_A, "[]", 1, partcv, params);
// compilenode returning idxres51
// compilenode returning *var_k
  params[0] = *var_k;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres52 = callmethod(idxres51, "[]", 1, partcv, params);
// compilenode returning idxres52
  int op_slot_left_50 = gc_frame_newslot(idxres52);
// compilenode returning *var_B
// compilenode returning *var_k
  params[0] = *var_k;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres53 = callmethod(*var_B, "[]", 1, partcv, params);
// compilenode returning idxres53
// compilenode returning *var_j
  params[0] = *var_j;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres54 = callmethod(idxres53, "[]", 1, partcv, params);
// compilenode returning idxres54
  int op_slot_right_50 = gc_frame_newslot(idxres54);
  params[0] = idxres54;
  partcv[0] = 1;
  Object prod56 = callmethod(idxres52, "*", 1, partcv, params);
// compilenode returning prod56
  int op_slot_right_49 = gc_frame_newslot(prod56);
  params[0] = prod56;
  partcv[0] = 1;
  Object sum58 = callmethod(*var_sum, "+", 1, partcv, params);
// compilenode returning sum58
  *var_sum = sum58;
  if (sum58 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_matrix_45_mult__apply39(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_sum = getfromclosure(closure, 0);
  Object *var_width = getfromclosure(closure, 1);
  Object *var_A = getfromclosure(closure, 2);
  Object *var_i = getfromclosure(closure, 3);
  Object *var_B = getfromclosure(closure, 4);
  Object *var_C = getfromclosure(closure, 5);
  Object self = *(getfromclosure(closure, 6));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_j = &(stackframe->slots[0]);
  *var_j = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 21
  setline(21);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num40 = alloc_Float64(0);
// compilenode returning num40
  *var_sum = num40;
  if (num40 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 22
  setline(22);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe42 = gc_frame_new();
  Object num44 = alloc_Float64(1);
// compilenode returning num44
  int op_slot_left_43 = gc_frame_newslot(num44);
// compilenode returning *var_width
  int op_slot_right_43 = gc_frame_newslot(*var_width);
  params[0] = *var_width;
  partcv[0] = 1;
  Object opresult46 = callmethod(num44, "..", 1, partcv, params);
// compilenode returning opresult46
  gc_frame_newslot(opresult46);
  Object block47 = alloc_Block(NULL, NULL, "lig/matrix-mult", 22);
  gc_frame_newslot(block47);
  block_savedest(block47);
  Object closure48 = createclosure(6, "_apply");
setclosureframe(closure48, stackframe);
  addtoclosure(closure48, var_sum);
  addtoclosure(closure48, var_A);
  addtoclosure(closure48, var_i);
  addtoclosure(closure48, var_B);
  addtoclosure(closure48, var_j);
  addtoclosure(closure48, selfslot);
  struct UserObject *uo48 = (struct UserObject*)block47;
  uo48->data[0] = (Object)closure48;
  Method *meth_meth_lig_47_matrix_45_mult__apply48 = addmethod2pos(block47, "_apply", &meth_lig_47_matrix_45_mult__apply48, 0);
int argcv_meth_lig_47_matrix_45_mult__apply48[] = {1};
meth_meth_lig_47_matrix_45_mult__apply48->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult__apply48);
  meth_meth_lig_47_matrix_45_mult__apply48->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult__apply48->definitionLine = 14;
// compilenode returning block47
  gc_frame_newslot(block47);
  params[0] = opresult46;
  params[1] = block47;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call61 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe42);
// compilenode returning call61
// Begin line 26
  setline(26);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe62 = gc_frame_new();
// Begin line 25
  setline(25);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_j
  gc_frame_newslot(*var_j);
// compilenode returning *var_sum
  gc_frame_newslot(*var_sum);
// compilenode returning *var_C
// compilenode returning *var_i
  params[0] = *var_i;
  gc_frame_newslot(params[0]);
  partcv[0] = 1;
  Object idxres63 = callmethod(*var_C, "[]", 1, partcv, params);
// compilenode returning idxres63
  params[0] = *var_j;
  params[1] = *var_sum;
  partcv[0] = 2;
  Object call64 = callmethod(idxres63, "[]:=",
    1, partcv, params);
  gc_frame_end(callframe62);
// compilenode returning call64
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_matrix_45_mult__apply32(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_width = getfromclosure(closure, 0);
  Object *var_sum = getfromclosure(closure, 1);
  Object *var_A = getfromclosure(closure, 2);
  Object *var_B = getfromclosure(closure, 3);
  Object *var_C = getfromclosure(closure, 4);
  Object self = *(getfromclosure(closure, 5));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_i = &(stackframe->slots[0]);
  *var_i = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 20
  setline(20);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe33 = gc_frame_new();
  Object num35 = alloc_Float64(1);
// compilenode returning num35
  int op_slot_left_34 = gc_frame_newslot(num35);
// compilenode returning *var_width
  int op_slot_right_34 = gc_frame_newslot(*var_width);
  params[0] = *var_width;
  partcv[0] = 1;
  Object opresult37 = callmethod(num35, "..", 1, partcv, params);
// compilenode returning opresult37
  gc_frame_newslot(opresult37);
  Object block38 = alloc_Block(NULL, NULL, "lig/matrix-mult", 20);
  gc_frame_newslot(block38);
  block_savedest(block38);
  Object closure39 = createclosure(7, "_apply");
setclosureframe(closure39, stackframe);
  addtoclosure(closure39, var_sum);
  addtoclosure(closure39, var_width);
  addtoclosure(closure39, var_A);
  addtoclosure(closure39, var_i);
  addtoclosure(closure39, var_B);
  addtoclosure(closure39, var_C);
  addtoclosure(closure39, selfslot);
  struct UserObject *uo39 = (struct UserObject*)block38;
  uo39->data[0] = (Object)closure39;
  Method *meth_meth_lig_47_matrix_45_mult__apply39 = addmethod2pos(block38, "_apply", &meth_lig_47_matrix_45_mult__apply39, 0);
int argcv_meth_lig_47_matrix_45_mult__apply39[] = {1};
meth_meth_lig_47_matrix_45_mult__apply39->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult__apply39);
  meth_meth_lig_47_matrix_45_mult__apply39->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult__apply39->definitionLine = 14;
// compilenode returning block38
  gc_frame_newslot(block38);
  params[0] = opresult37;
  params[1] = block38;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call66 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe33);
// compilenode returning call66
  gc_frame_end(frame);
  return call66;
}
Object meth_lig_47_matrix_45_mult_main17(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 3, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(8, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "main");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[2];
  int partcv[2];
  Object *var_sys = getfromclosure(closure, 0);
  Object *var_width = getfromclosure(closure, 1);
  Object *var_avg = getfromclosure(closure, 2);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_n = &(stackframe->slots[0]);
  *var_n = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
  Object *var_time = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "time");
  Object *var_A = &(stackframe->slots[3]);
  setframeelementname(stackframe, 3, "A");
  Object *var_B = &(stackframe->slots[4]);
  setframeelementname(stackframe, 4, "B");
  Object *var_sum = &(stackframe->slots[5]);
  setframeelementname(stackframe, 5, "sum");
  Object *var_C = &(stackframe->slots[6]);
  setframeelementname(stackframe, 6, "C");
  Object *var_tt = &(stackframe->slots[7]);
  setframeelementname(stackframe, 7, "tt");
// Begin line 14
  setline(14);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe18 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call19 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe18);
// compilenode returning call19
// compilenode returning call19
  *var_time = call19;
  if (call19 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 15
  setline(15);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe20 = gc_frame_new();
  partcv[0] = 0;
  Object call21 = callmethodflags(self, "initAr", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe20);
// compilenode returning call21
  *var_A = call21;
  if (call21 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 16
  setline(16);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe22 = gc_frame_new();
  partcv[0] = 0;
  Object call23 = callmethodflags(self, "initAr", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe22);
// compilenode returning call23
  *var_B = call23;
  if (call23 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 17
  setline(17);
  setmodule(modulename);
  setsource(originalSourceLines);
  *var_sum = undefined;
// compilenode returning none
// Begin line 18
  setline(18);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe24 = gc_frame_new();
  partcv[0] = 0;
  Object call25 = callmethodflags(self, "initAr", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe24);
// compilenode returning call25
  *var_C = call25;
  if (call25 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 19
  setline(19);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe26 = gc_frame_new();
  Object num28 = alloc_Float64(1);
// compilenode returning num28
  int op_slot_left_27 = gc_frame_newslot(num28);
// compilenode returning *var_width
  int op_slot_right_27 = gc_frame_newslot(*var_width);
  params[0] = *var_width;
  partcv[0] = 1;
  Object opresult30 = callmethod(num28, "..", 1, partcv, params);
// compilenode returning opresult30
  gc_frame_newslot(opresult30);
  Object block31 = alloc_Block(NULL, NULL, "lig/matrix-mult", 19);
  gc_frame_newslot(block31);
  block_savedest(block31);
  Object closure32 = createclosure(6, "_apply");
setclosureframe(closure32, stackframe);
  addtoclosure(closure32, var_width);
  addtoclosure(closure32, var_sum);
  addtoclosure(closure32, var_A);
  addtoclosure(closure32, var_B);
  addtoclosure(closure32, var_C);
  addtoclosure(closure32, selfslot);
  struct UserObject *uo32 = (struct UserObject*)block31;
  uo32->data[0] = (Object)closure32;
  Method *meth_meth_lig_47_matrix_45_mult__apply32 = addmethod2pos(block31, "_apply", &meth_lig_47_matrix_45_mult__apply32, 0);
int argcv_meth_lig_47_matrix_45_mult__apply32[] = {1};
meth_meth_lig_47_matrix_45_mult__apply32->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult__apply32);
  meth_meth_lig_47_matrix_45_mult__apply32->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult__apply32->definitionLine = 14;
// compilenode returning block31
  gc_frame_newslot(block31);
  params[0] = opresult30;
  params[1] = block31;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call68 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe26);
// compilenode returning call68
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe70 = gc_frame_new();
// compilenode returning *var_sys
  partcv[0] = 0;
  Object call71 = callmethod(*var_sys, "cputime",
    1, partcv, params);
  gc_frame_end(callframe70);
// compilenode returning call71
// compilenode returning call71
  int op_slot_left_69 = gc_frame_newslot(call71);
// compilenode returning *var_time
  int op_slot_right_69 = gc_frame_newslot(*var_time);
  params[0] = *var_time;
  partcv[0] = 1;
  Object diff73 = callmethod(call71, "-", 1, partcv, params);
// compilenode returning diff73
  *var_tt = diff73;
  if (diff73 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
// Begin line 29
  setline(29);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  int op_slot_left_74 = gc_frame_newslot(*var_avg);
// compilenode returning *var_tt
  int op_slot_right_74 = gc_frame_newslot(*var_tt);
  params[0] = *var_tt;
  partcv[0] = 1;
  Object sum76 = callmethod(*var_avg, "+", 1, partcv, params);
// compilenode returning sum76
  *var_avg = sum76;
  if (sum76 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
// Begin line 30
  setline(30);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit82 == NULL) {
    strlit82 = alloc_String("Run ");
    gc_root(strlit82);
  }
// compilenode returning strlit82
  int op_slot_left_81 = gc_frame_newslot(strlit82);
// compilenode returning *var_n
  int op_slot_right_81 = gc_frame_newslot(*var_n);
  params[0] = *var_n;
  partcv[0] = 1;
  Object opresult84 = callmethod(strlit82, "++", 1, partcv, params);
// compilenode returning opresult84
  int op_slot_left_80 = gc_frame_newslot(opresult84);
  if (strlit85 == NULL) {
    strlit85 = alloc_String(": ");
    gc_root(strlit85);
  }
// compilenode returning strlit85
  int op_slot_right_80 = gc_frame_newslot(strlit85);
  params[0] = strlit85;
  partcv[0] = 1;
  Object opresult87 = callmethod(opresult84, "++", 1, partcv, params);
// compilenode returning opresult87
  int op_slot_left_79 = gc_frame_newslot(opresult87);
// compilenode returning *var_tt
  int op_slot_right_79 = gc_frame_newslot(*var_tt);
  params[0] = *var_tt;
  partcv[0] = 1;
  Object opresult89 = callmethod(opresult87, "++", 1, partcv, params);
// compilenode returning opresult89
  int op_slot_left_78 = gc_frame_newslot(opresult89);
  if (strlit90 == NULL) {
    strlit90 = alloc_String("s");
    gc_root(strlit90);
  }
// compilenode returning strlit90
  int op_slot_right_78 = gc_frame_newslot(strlit90);
  params[0] = strlit90;
  partcv[0] = 1;
  Object opresult92 = callmethod(opresult89, "++", 1, partcv, params);
// compilenode returning opresult92
  params[0] = opresult92;
  Object call93 = gracelib_print(NULL, 1,  params);
// compilenode returning call93
  gc_frame_end(frame);
  return call93;
}
Object meth_lig_47_matrix_45_mult_width95(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 4, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "width");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_width = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_width
  gc_frame_end(frame);
  return *var_width;
}
Object meth_lig_47_matrix_45_mult_avg97(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 5, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(1, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "avg");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  Object params[1];
  int partcv[1];
  Object *var_avg = getfromclosure(closure, 0);
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *selfslot = &(stackframe->slots[0]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
// compilenode returning *var_avg
  gc_frame_end(frame);
  return *var_avg;
}
Object meth_lig_47_matrix_45_mult_avg_58__61_98(Object self, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)self;
  Object closure = getdatum((Object)uo, 6, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "avg:=");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object *var_avg = getfromclosure(closure, 0);
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
  *var_avg = *var__var_assign_tmp;
  if (*var__var_assign_tmp == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// compilenode returning none
  gc_frame_end(frame);
  return none;
}
Object meth_lig_47_matrix_45_mult__apply107(Object realself, int nparts, int *argcv, Object *args, int32_t flags) {
  struct UserObject *uo = (struct UserObject*)realself;
  Object closure = getdatum((Object)uo, 0, (flags>>24)&0xff);
  struct StackFrameObject *stackframe = alloc_StackFrame(2, getclosureframe(closure));
  pushclosure(closure);
  pushstackframe(stackframe, "_apply");
  int frame = gc_frame_new();
  gc_frame_newslot((Object)stackframe);
  if (nparts > 0 && argcv[0] < 1)
    gracedie("insufficient arguments to method");
  Object params[1];
  int partcv[1];
  Object self = *(getfromclosure(closure, 0));
  sourceObject = self;
  int i;
  int curarg = 0;
  int pushcv[] = {1};
  Object *var_i = &(stackframe->slots[0]);
  *var_i = args[curarg];
  curarg++;
  Object *selfslot = &(stackframe->slots[1]);
  *selfslot = self;
  setframeelementname(stackframe, 0, "self");
// Begin line 33
  setline(33);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe108 = gc_frame_new();
// compilenode returning *var_i
  gc_frame_newslot(*var_i);
  params[0] = *var_i;
  partcv[0] = 1;
  Object call109 = callmethodflags(self, "main", 1, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe108);
// compilenode returning call109
  gc_frame_end(frame);
  return call109;
}
Object module_lig_47_matrix_45_mult_init() {
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
  setclassname(self, "Module<lig/matrix-mult>");
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
Object *var_sys = alloc_var();
  Object *var_width = &(stackframe->slots[1]);
  setframeelementname(stackframe, 1, "width");
  Object *var_avg = &(stackframe->slots[2]);
  setframeelementname(stackframe, 2, "avg");
// Begin line 3
  setline(3);
  setmodule(modulename);
  setsource(originalSourceLines);
  struct UserObject *uo0 = (struct UserObject*)self;
  uo0->data[1] = emptyclosure;
  Method *meth_meth_lig_47_matrix_45_mult_inline0 = addmethod2pos(self, "inline", &meth_lig_47_matrix_45_mult_inline0, 1);
int argcv_meth_lig_47_matrix_45_mult_inline0[] = {0};
meth_meth_lig_47_matrix_45_mult_inline0->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_inline0);
  meth_meth_lig_47_matrix_45_mult_inline0->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_inline0->definitionLine = 3;
// compilenode returning 
// Begin line 4
  setline(4);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure1 = createclosure(1, "initAr");
setclosureframe(closure1, stackframe);
  addtoclosure(closure1, var_width);
  struct UserObject *uo1 = (struct UserObject*)self;
  uo1->data[2] = (Object)closure1;
  Method *meth_meth_lig_47_matrix_45_mult_initAr1 = addmethod2pos(self, "initAr", &meth_lig_47_matrix_45_mult_initAr1, 2);
int argcv_meth_lig_47_matrix_45_mult_initAr1[] = {0};
meth_meth_lig_47_matrix_45_mult_initAr1->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_initAr1);
  meth_meth_lig_47_matrix_45_mult_initAr1->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_initAr1->definitionLine = 4;
// compilenode returning 
// Begin line 13
  setline(13);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure17 = createclosure(3, "main");
setclosureframe(closure17, stackframe);
  addtoclosure(closure17, var_sys);
  addtoclosure(closure17, var_width);
  addtoclosure(closure17, var_avg);
  struct UserObject *uo17 = (struct UserObject*)self;
  uo17->data[3] = (Object)closure17;
  Method *meth_meth_lig_47_matrix_45_mult_main17 = addmethod2pos(self, "main", &meth_lig_47_matrix_45_mult_main17, 3);
int argcv_meth_lig_47_matrix_45_mult_main17[] = {1};
meth_meth_lig_47_matrix_45_mult_main17->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_main17);
  meth_meth_lig_47_matrix_45_mult_main17->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_main17->definitionLine = 13;
// compilenode returning 
// Begin line 2
  setline(2);
  setmodule(modulename);
  setsource(originalSourceLines);
// Import of sys as sys
  if (module_sys == NULL)
    module_sys = module_sys_init();
  *var_sys = module_sys;
// compilenode returning none
  Object num94 = alloc_Float64(75);
// compilenode returning num94
  *var_width = num94;
  if (num94 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure95 = createclosure(1, "width");
setclosureframe(closure95, stackframe);
  addtoclosure(closure95, var_width);
  struct UserObject *uo95 = (struct UserObject*)self;
  uo95->data[4] = (Object)closure95;
  Method *meth_meth_lig_47_matrix_45_mult_width95 = addmethod2pos(self, "width", &meth_lig_47_matrix_45_mult_width95, 4);
int argcv_meth_lig_47_matrix_45_mult_width95[] = {0};
meth_meth_lig_47_matrix_45_mult_width95->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_width95);
  meth_meth_lig_47_matrix_45_mult_width95->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_width95->definitionLine = 28;
// compilenode returning 
// compilenode returning none
// Begin line 12
  setline(12);
  setmodule(modulename);
  setsource(originalSourceLines);
  Object num96 = alloc_Float64(0);
// compilenode returning num96
  *var_avg = num96;
  if (num96 == undefined)
    callmethod(none, "assignment", 0, NULL, NULL);
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure97 = createclosure(1, "avg");
setclosureframe(closure97, stackframe);
  addtoclosure(closure97, var_avg);
  struct UserObject *uo97 = (struct UserObject*)self;
  uo97->data[5] = (Object)closure97;
  Method *meth_meth_lig_47_matrix_45_mult_avg97 = addmethod2pos(self, "avg", &meth_lig_47_matrix_45_mult_avg97, 5);
int argcv_meth_lig_47_matrix_45_mult_avg97[] = {0};
meth_meth_lig_47_matrix_45_mult_avg97->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_avg97);
  meth_meth_lig_47_matrix_45_mult_avg97->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_avg97->definitionLine = 28;
// compilenode returning 
// Begin line 28
  setline(28);
  setmodule(modulename);
  setsource(originalSourceLines);
  block_savedest(self);
  Object closure98 = createclosure(1, "avg:=");
setclosureframe(closure98, stackframe);
  addtoclosure(closure98, var_avg);
  struct UserObject *uo98 = (struct UserObject*)self;
  uo98->data[6] = (Object)closure98;
  Method *meth_meth_lig_47_matrix_45_mult_avg_58__61_98 = addmethod2pos(self, "avg:=", &meth_lig_47_matrix_45_mult_avg_58__61_98, 6);
int argcv_meth_lig_47_matrix_45_mult_avg_58__61_98[] = {1};
meth_meth_lig_47_matrix_45_mult_avg_58__61_98->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult_avg_58__61_98);
  meth_meth_lig_47_matrix_45_mult_avg_58__61_98->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult_avg_58__61_98->definitionLine = 28;
// compilenode returning 
// compilenode returning none
// Begin line 32
  setline(32);
  setmodule(modulename);
  setsource(originalSourceLines);
  int callframe100 = gc_frame_new();
  Object num102 = alloc_Float64(1);
// compilenode returning num102
  int op_slot_left_101 = gc_frame_newslot(num102);
  Object num103 = alloc_Float64(15);
// compilenode returning num103
  int op_slot_right_101 = gc_frame_newslot(num103);
  params[0] = num103;
  partcv[0] = 1;
  Object opresult105 = callmethod(num102, "..", 1, partcv, params);
// compilenode returning opresult105
  gc_frame_newslot(opresult105);
  Object block106 = alloc_Block(NULL, NULL, "lig/matrix-mult", 32);
  gc_frame_newslot(block106);
  block_savedest(block106);
  Object closure107 = createclosure(1, "_apply");
setclosureframe(closure107, stackframe);
  addtoclosure(closure107, selfslot);
  struct UserObject *uo107 = (struct UserObject*)block106;
  uo107->data[0] = (Object)closure107;
  Method *meth_meth_lig_47_matrix_45_mult__apply107 = addmethod2pos(block106, "_apply", &meth_lig_47_matrix_45_mult__apply107, 0);
int argcv_meth_lig_47_matrix_45_mult__apply107[] = {1};
meth_meth_lig_47_matrix_45_mult__apply107->type = alloc_MethodType(1, argcv_meth_lig_47_matrix_45_mult__apply107);
  meth_meth_lig_47_matrix_45_mult__apply107->definitionModule = modulename;
  meth_meth_lig_47_matrix_45_mult__apply107->definitionLine = 28;
// compilenode returning block106
  gc_frame_newslot(block106);
  params[0] = opresult105;
  params[1] = block106;
  partcv[0] = 1;
  partcv[1] = 1;
  Object call111 = callmethodflags(prelude, "for()do", 2, partcv, params, CFLAG_SELF);
  gc_frame_end(callframe100);
// compilenode returning call111
// Begin line 35
  setline(35);
  setmodule(modulename);
  setsource(originalSourceLines);
  if (strlit114 == NULL) {
    strlit114 = alloc_String("average : ");
    gc_root(strlit114);
  }
// compilenode returning strlit114
  int op_slot_left_113 = gc_frame_newslot(strlit114);
// compilenode returning *var_avg
  int op_slot_left_115 = gc_frame_newslot(*var_avg);
  Object num116 = alloc_Float64(15);
// compilenode returning num116
  int op_slot_right_115 = gc_frame_newslot(num116);
  params[0] = num116;
  partcv[0] = 1;
  Object quotient118 = callmethod(*var_avg, "/", 1, partcv, params);
// compilenode returning quotient118
  int op_slot_right_113 = gc_frame_newslot(quotient118);
  params[0] = quotient118;
  partcv[0] = 1;
  Object opresult120 = callmethod(strlit114, "++", 1, partcv, params);
// compilenode returning opresult120
  int op_slot_left_112 = gc_frame_newslot(opresult120);
  if (strlit121 == NULL) {
    strlit121 = alloc_String("s");
    gc_root(strlit121);
  }
// compilenode returning strlit121
  int op_slot_right_112 = gc_frame_newslot(strlit121);
  params[0] = strlit121;
  partcv[0] = 1;
  Object opresult123 = callmethod(opresult120, "++", 1, partcv, params);
// compilenode returning opresult123
  params[0] = opresult123;
  Object call124 = gracelib_print(NULL, 1,  params);
// compilenode returning call124
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
  module_lig_47_matrix_45_mult_init();
  gracelib_stats();
  return 0;
}
