# ############################################################################ #
#                                                                              #
#                                                         :::      ::::::::    #
#    captured.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <me@cacharle.xyz>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/11 12:16:25 by charles           #+#    #+#              #
#    Updated: 2020/10/15 08:49:01 by cacharle         ###   ########.fr        #
#                                                                              #
# ############################################################################ #

import config


class Captured:
    def __init__(self, output: str, status: int, files_content: [str], is_timeout: bool = False):
        """Captured class
           output:        captured content
           status:        command status
           files_content: content of the files altered by the command
           is_timeout:    the command has timed out
        """
        # if config.PROMPT_OBJECT is not None:
        #     output = output.replace(config.PROMPT_OBJECT + "\n", "")
        #     output = output.replace(config.PROMPT_OBJECT, "")
        lines = output.split('\n')
        for i, l in enumerate(lines):
            # if l.find(config.PROMPT_OBJECT) == 0:
            #     l.replace(config.PROMPT_OBJECT, "")
            if l.find(config.REFERENCE_ERROR_BEGIN) == 0:
                lines[i] = l.replace(config.REFERENCE_ERROR_BEGIN, config.MINISHELL_ERROR_BEGIN, 1)
            elif l.find(config.REFERENCE_PATH + ": ") == 0:
                lines[i] = l.replace(config.REFERENCE_PATH + ": ", config.MINISHELL_ERROR_BEGIN, 1)

        self.output = '\n'.join(lines)

        self.status = status
        self.files_content = files_content
        self.is_timeout = is_timeout

    def __eq__(self, other: 'Captured') -> bool:
        if self.is_timeout:
            return self.is_timeout == other.is_timeout
        return (self.output == other.output
                and self.status == other.status
                and all([x == y for x, y in zip(self.files_content, other.files_content)]))

    @staticmethod
    def timeout():
        """Create a new captured timeout"""
        return Captured("", 0, [], is_timeout=True)
