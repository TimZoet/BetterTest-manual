Custom Mixins
=============

New mixins can be created my implementing the :code:`bt::IMixin` interface. Presently, only the :code:`getName` method
needs to be implemented. This should return a unique name by which the mixin can be identified. The name is mainly used
when storing test results.

It is entirely up to you how your mixins function exactly. However, it is generally best to follow the standards set by
the built-in mixins. Each check method you add should:

1. Return an object of type :code:`bt::CheckResult` to allow control flow.
2. Have a defaulted :code:`std::source_location` parameter to provide information about the location of any failed 
   checks.
3. Use the inherited :code:`recordResult` method to keep track of all results. This method conveniently returns a
   :code:`bt::CheckResult`.

.. code-block:: cpp

    class MyFirstMixin : public bt::IMixin
    {
    public:
        [[nodiscard]] std::string getName() const override
        {
            return "myMixin";
        }

    protected:
        bt::CheckResult isNegative(int32_t value, const std::source_location& loc = std::source_location::current())
        {
            if (value < 0)
                return recordResult(result_t::success, loc, "");
            else
                return recordResult(result_t::failure, loc, std::format("{} is not negative", value));
        }

    private:
        ...
    };

Custom Output
-------------

.. note::

    Not yet implemented.
