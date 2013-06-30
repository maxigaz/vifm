#include <stdlib.h>

#include "seatest.h"

#include "../../src/utils/env.h"
#include "../../src/utils/utils.h"

#define VAR_A       "VAR_A"
#define VAR_A_VAL   "VAR_A_VAL"
#define VAR_B       "VAR_B"
#define VAR_B_VAL   "VAR_B_VAL"

static void
setup(void)
{
	env_set(VAR_A, VAR_A_VAL);
	env_set(VAR_B, VAR_B_VAL);
}

static void
teardown(void)
{
	env_remove(VAR_A);
	env_remove(VAR_B);
}

static void
test_empty_string_ok(void)
{
	const char *const path = "";
	char *const expanded_path = expand_envvars(path);
	assert_string_equal("", expanded_path);
	free(expanded_path);
}

static void
test_no_envvars_ok(void)
{
	const char *const path = "/usr/bin/vifm";
	char *const expanded_path = expand_envvars(path);
	assert_string_equal(path, expanded_path);
	free(expanded_path);
}

static void
test_expanding_works(void)
{
	const char *const path = "/$" VAR_A "/$" VAR_B "/vifm";
	char *const expanded_path = expand_envvars(path);
	assert_string_equal("/" VAR_A_VAL "/" VAR_B_VAL "/vifm", expanded_path);
	free(expanded_path);
}

static void
test_ends_with_dollar_sign_ok(void)
{
	const char *const path = "/usr/bin/vifm$";
	char *const expanded_path = expand_envvars(path);
	assert_string_equal(path, expanded_path);
	free(expanded_path);
}

static void
test_double_dollar_sign_folded_ok(void)
{
	const char *const path = "/usr/b$$in/vifm";
	char *const expanded_path = expand_envvars(path);
	assert_string_equal("/usr/b$in/vifm", expanded_path);
	free(expanded_path);
}

void
expand_envvars_tests(void)
{
	test_fixture_start();

	fixture_setup(setup);
	fixture_teardown(teardown);

	run_test(test_empty_string_ok);
	run_test(test_no_envvars_ok);
	run_test(test_expanding_works);
	run_test(test_ends_with_dollar_sign_ok);
	run_test(test_double_dollar_sign_folded_ok);

	test_fixture_end();
}

/* vim: set tabstop=2 softtabstop=2 shiftwidth=2 noexpandtab cinoptions-=(0 : */
/* vim: set cinoptions+=t0 : */
