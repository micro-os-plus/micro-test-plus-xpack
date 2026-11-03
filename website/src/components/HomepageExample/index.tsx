import CodeBlock from '@theme/CodeBlock';
import Heading from '@theme/Heading';

const source = `#include <micro-os-plus/micro-test-plus.h>

// Define a shortcut for the namespace.
namespace mt = micro_os_plus::micro_test_plus;

// Create the test runner.
mt::runner tr;

int
main (int argc, char* argv[])
{
  // Initialise the runner with command line arguments.
  tr.initialise (argc, argv);

  // Add the top suite and get a reference to it.
  auto& ts = tr.add_top_suite ();

  // Add a test case to the top suite; its body runs immediately.
  ts.test ("Check truth", [] (auto& t)
    {
      // Check that 6 times 7 equals 42.
      t.expect (mt::eq (6 * 7, 42)) << "the answer is 42";
    });

  // Run the registered suites, if any, and return the test result.
  return tr.run_suites ();
}`;

const tapOutput = `TAP version 14
# Subtest: minimal-test
    # Subtest: Check truth
        ok 1 - the answer is 42
        1..1
    ok 1 - Check truth # { passed, 1 check }
    1..1
ok 1 - minimal-test # { passed, 1 check in 1 test case }
1..1`;

const humanOutput = `µTest++ human-readable report
• minimal-test
    • Check truth
        ✓ the answer is 42
    ✓ Check truth - passed (1 check)
✓ minimal-test - passed (1 check in 1 test case)`;

export default function HomepageExample(): JSX.Element {
  return (
    <section className="container margin-vert--lg">
      <Heading as="h2" className="text--center">A first test</Heading>
      <p className="text--center">
        The outputs below were produced by running the program
        with <code>--verbose</code>; the header lines, the timings, and the
        totals were omitted.
      </p>
      <div className="row">
        <div className="col col--6">
          <CodeBlock language="cpp" title="minimal-test.cpp">{source}</CodeBlock>
        </div>
        <div className="col col--6">
          <CodeBlock language="text" title="TAP output (default)">{tapOutput}</CodeBlock>
          <CodeBlock language="text" title="Human-readable output (--reporter=human)">{humanOutput}</CodeBlock>
        </div>
      </div>
    </section>
  );
}
