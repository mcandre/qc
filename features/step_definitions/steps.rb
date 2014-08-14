Given(/^the program has finished$/) do
  `make clean 2>/dev/null`

  @cucumber = `make`
end

Then(/^the output is correct for each test$/) do
  lines = @cucumber.split("\n")

  expect(lines.length).to be >= 15

  expect(lines[0 .. 2].join("\n")).to eq('mkdir -p bin/
clang -O2 -Wall -Wextra -Wmost -Weverything -Wno-pointer-arith -o bin/example example.c qc.c -lgc
bin/example')

  expect(lines[3]).to eq('+++ OK, passed 100 tests.')
  expect(lines[4]).to eq('+++ OK, passed 100 tests.')
  expect(lines[5 .. 6].join("\n")).to match(/^\*\*\* Failed!\n[0-9]+/m)
  expect(lines[7 .. 10].join("\n")).to match(/^\*\*\* Failed!(\n[0-9]+){3}/m)
  expect(lines[11 .. 13].join("\n")).to match(/^\*\*\* Failed!\n\'[0-9]\'\n[0-9]/m)
  expect(lines[14 .. -1].join("\n")).to match(/^\*\*\* Failed!\n.*/m)
end
