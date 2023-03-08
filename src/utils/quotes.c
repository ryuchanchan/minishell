#include "quotes.h"
/*　閉じがない引用符もstatusを変更してしまう、以降に閉じが存在するか確認する処理を追加するかしないか?　*/
bool	is_quote_end(const t_status_quotes status, const char *src, size_t i)
{
	if (status == IN_SINGLE_QUOTE && src[i] == '\'')
		return (true);
	return (status == IN_DOUBLE_QUOTE && src[i] == '"');
}

bool	is_double_quote_begin(const t_status_quotes status, const char *src, size_t i)
{
	return (status == NONE && src[i] == '"');
}

bool	is_single_quote_begin(const t_status_quotes status, const char *src, size_t i)
{
	return (status == NONE && src[i] == '\'');
}

void update_status(t_status_quotes *status, t_status_quotes next, size_t *i_p)
{
	*status = next;
	(*i_p)++;
}
