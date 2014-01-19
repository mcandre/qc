guard :shell do
  watch('Makefile|.*\.(c|h)') do |m|
    title = 'Test'
    eager 'make test'
    status = ($?.success? && :success) || :failed
    n '', title, status
    ''
  end
end
