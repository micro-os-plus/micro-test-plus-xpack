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

  // Add the default test suite.
  auto& ts = tr.add_top_suite ();

  // Add test cases to the test suite.
  ts.test ("Check truth", [] (auto& t)
    {
      t.expect (mt::eq (6 * 7, 42)) << "the answer";
    });

  // Run the tests and return the test result.
  return tr.run_suites ();
}`;

const output = `TAP version 14
# Subtest: minimal-test
    # Subtest: Check truth
        ok 1 - the answer
        1..1
    ok 1 - Check truth # { passed, 1 check }
    1..1
ok 1 - minimal-test # { passed, 1 check in 1 test case }
1..1`;

export default function HomepageExample(): JSX.Element {
  return (
    <section className="container margin-vert--lg">
      <Heading as="h2" className="text--center">A first test</Heading>
      <div className="row">
        <div className="col col--6">
          <CodeBlock language="cpp" title="minimal-test.cpp">{source}</CodeBlock>
        </div>
        <div className="col col--6">
          <CodeBlock language="text" title="Output">{output}</CodeBlock>
        </div>
      </div>
    </section>
  );
}
