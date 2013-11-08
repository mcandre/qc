guard :shell do
  watch('Gemfile') do |m|
    title = 'Bundler output'
    msg = 'Bundler Failure'
    status = :failed

    if `bundle`
      msg = 'Bundled'
      status = :status
    end

    n msg, title, status

    "-> #{msg}"
  end

  watch('Makefile|.*\.(c|h)') do |m|
    title = 'Test output'
    msg = 'Output does not match test output'
    status = :failed

    if `make test`
      msg = 'Matches test output'
      status = :success
    end

    n msg, title, status

    "-> #{msg}"
  end
end
