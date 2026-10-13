import CodeBlock from '@theme/CodeBlock';
import Heading from '@theme/Heading';

const source = `#include <micro-os-plus/micro-test-plus.h>

// Define a shortcut for the namespace.
namespace mt = micro_os_plus::micro_test_plus;

int
main (int argc, char* argv[])
{
  // Create the test runner.
  mt::runner tr;
  // Initialise it and get the default test suite.
  auto& ts = tr.initialise (argc, argv);

  // Add test cases to the test suite.
  ts.test ("Check various conditions", [] (auto& t)
    {
      // Check various conditions.
      t.expect (mt::eq (compute_answer (), 42)) << "answer is 42";
      t.expect (compute_condition ()) << "condition is true";
    });

  // Run the tests and return the test result.
  return tr.run ();
}`;

const output = `TAP version 14
# Subtest: minimal-test
    # Subtest: Check various conditions
        ok 1 - answer is 42
        ok 2 - condition is true
        1..2
    ok 1 - Check various conditions # { passed, 2 checks }
    1..1
ok 1 - minimal-test # { passed, 2 checks in 1 test case }
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
