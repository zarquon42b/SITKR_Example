require(SimpleITK)
testimg <- Image(10,10,10,"sitkInt8")
dyn.load("src/SimpleITKRtest.so")
.Call("mytest",testimg@ref)
