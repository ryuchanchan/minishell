#ifndef VALIDATE_AND_EXPAND_H
# define VALIDATE_AND_EXPAND_H

# include "ms_error.h"
# include "ms_state.h"
# include "expansion.h"

bool	validate_and_expand(t_list *tokens, t_ms_state *state_p, bool is_quote_not_closed);

#endif
