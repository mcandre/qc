Given(/^the program has finished$/) do
  `make clean 2>/dev/null`

  @cucumber = `make`
end

Then(/^the output is correct for each test$/) do
  lines = @cucumber.split("\n")

  lines.length.should >= 14

  lines[0 .. 1].join("\n").should == 'clang -O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith -o example example.c qc.c -lgc
./example'

  lines[2].should == '+++ OK, passed 100 tests.'
  lines[3 .. 4].join("\n").should =~ /^\*\*\* Failed!\n[0-9]+/m
  lines[5 .. 8].join("\n").should =~ /^\*\*\* Failed!(\n[0-9]+){3}/m
  lines[9 .. 11].join("\n").should =~ /^\*\*\* Failed!\n\'[0-9]\'\n[0-9]/m
  lines[12 .. -1].join("\n").should =~ /^\*\*\* Failed!\n.*/m
end
