guard :shell do
  watch('Makefile|.*\.(c|h)') do |m|
    title = 'Test'
    msg = `make test`
    status = ($?.success? && :success) || :failed

    n msg, title, status
    "-> #{msg}"
  end
end
