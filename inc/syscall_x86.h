/*
** main.c for  in /home/fritsc_h/AUSP_strace/src
**
** Made by Harold Fritsch
** Login   <fritsc_h@epitech.net>
**
** Started on  Thu May  1 18:27:53 2014 Harold Fritsch
** Last update Fri May  2 16:54:41 2014 Harold Fritsch
*/

#ifndef SYSCALL_X86_H_INCLUDED
# define SYSCALL_X86_H_INCLUDED

/* NAME RTYPE PARAMS */
t_syscall_info	g_syscall_x86[] = {
  {"restart_syscall", "long", {"void", NULL}},
  {"_exit", "void", {"int", NULL}},
  {"fork", "pid_t", {"void", NULL}},
  {"read", "ssize_t", {"int", "void*", "size_t", NULL}},
  {"write", "ssize_t", {"int", "void*", "size_t", NULL}},
  {"open", "int", {"char*", "int", NULL}},
  {"close", "int", {"int", NULL}},
  {"waitpid", "pid_t", {"pid_t", "int*", "int", NULL}},
  {"creat", "int", {"char*", "mode_t", NULL}},
  {"link", "int", {"char*", "char*", NULL}},
  {"unlink", "int", {"char*", NULL}},
  {"execve", "int", {"char*", "char**", "char**", NULL}},
  {"chdir", "int", {"char*", NULL}},
  {"time", "time_t", {"time_t*", NULL}},
  {"mknod", "int", {"char*", "mode_t", "dev_t", NULL}},
  {"chmod", "int", {"char*", "mode_t", NULL}},
  {"lchown", "int", {"char*", "uid_t", "gid_t", NULL}},
  {"break", NULL, {NULL}},
  {"oldstat", NULL, {NULL}},
  {"lseek", "off_t", {"int", "off_t", "int", NULL}},
  {"getpid", "pid_t", {"void", NULL}},
  {"mount", "int", {"char*", "char*", "char*", "unsigned long", "void*", NULL}},
  {"oldumount", NULL, {NULL}},
  {"setuid", "int", {"uid_t", NULL}},
  {"getuid", "uid_t", {"void", NULL}},
  {"stime", "int", {"time_t*", NULL}},
  {"ptrace", "long", {"enum __ptrace_request", "pid_t", "void*", "void*", NULL}},
  {"alarm", "unsigned int", {"unsigned int", NULL}},
  {"oldfstat", NULL, {NULL}},
  {"pause", "int", {"void", NULL}},
  {"utime", "int", {"char*", "struct utimbuf*", NULL}},
  {"stty", NULL, {NULL}},
  {"gtty", NULL, {NULL}},
  {"access", "int", {"char*", "int", NULL}},
  {"nice", "int", {"int", NULL}},
  {"ftime", "int", {"struct timeb*", NULL}},
  {"sync", "void", {"void", NULL}},
  {"kill", "int", {"pid_t", "int", NULL}},
  {"rename", "int", {"char*", "char*", NULL}},
  {"mkdir", "int", {"char*", "mode_t", NULL}},
  {"rmdir", "int", {"char*", NULL}},
  {"dup", "int", {"int", NULL}},
  {"pipe", "int", {"int[2]", NULL}},
  {"times", "clock_t", {"struct tms*", NULL}},
  {"prof", NULL, {NULL}},
  {"brk", "void*", {"void*", NULL}},
  {"setgid", "int", {"gid_t", NULL}},
  {"getgid", "uid_t", {"void", NULL}},
  {"signal", "sighandler_t", {"int", "sighandler_t", NULL}},
  {"geteuid", "uid_t", {"void", NULL}},
  {"getegid", "gid_t", {"void", NULL}},
  {"acct", "int", {"char*", NULL}},
  {"umount", "int", {"char*", NULL}},
  {"lock", NULL, {NULL}},
  {"ioctl", "int", {"int", "int", "...", NULL}},
  {"fcntl", "int", {"int", "int", "...", NULL}},
  {"mpx", NULL, {NULL}},
  {"setpgid", "int", {"pid_t", NULL}},
  {"ulimit", "long", {"int", "long", NULL}},
  {"oldolduname", "int", {"struct utsname*", NULL}},
  {"umask", "mode_t", {"mode_t", NULL}},
  {"chroot", "int", {"char*", NULL}},
  {"ustat", "int", {"dev_t", "struct ustat*", NULL}},
  {"dup2", "int", {"int", "int", NULL}},
  {"getppid", "pid_t", {"void", NULL}},
  {"getpgrp", "pid_t", {"void", NULL}},
  {"setsid", "pid_t", {"void", NULL}},
  {"sigaction", "int", {"int", "struct sigaction*", "struct sigaction*", NULL}},
  {"sgetmask", "long", {NULL}},
  {"ssetmask", "long", {"long", NULL}},
  {"setreuid", "int", {"uid_t", "uid_t", NULL}},
  {"setregid", "int", {"gid_t", "gid_t", NULL}},
  {"sigsuspend", "int", {"sigset_t*", NULL}},
  {"sigpending", "int", {"sigset_t*", NULL}},
  {"sethostname", "int", {"char*", "size_t", NULL}},
  {"setrlimit", "int", {"int", "struct rlimit*", NULL}},
  {"old_getrlimit", NULL, {NULL}},
  {"getrusage", "int", {"int", "struct rusage*", NULL}},
  {"gettimeofday", "int", {"struct timeval*", "struct timezone*", NULL}},
  {"settimeofday", "int", {"struct timeval*", "struct simezone*", NULL}},
  {"getgroups", "int", {"int", "gid_t[]", NULL}},
  {"setgroups", "int", {"size_t", "gid_t*", NULL}},
  {"oldselect", NULL, {NULL}},
  {"symlink", "int", {"char*", "char*", NULL}},
  {"oldlstat", NULL, {NULL}},
  {"readlink", "ssize_t", {"char*", "char*", "size_t", NULL}},
  {"uselib", "int", {"char*", NULL}},
  {"swapon", "int", {"char*", "int", NULL}},
  {"reboot", "int", {"int", NULL}},
  {"readdir", "int", {"DIR*", "struct dirent*", "struct dirent**", NULL}},
  {"old_mmap", NULL, {NULL}},
  {"munmap", "int", {"void*", "size_t", NULL}},
  {"truncate", "int", {"char*", "off_t", NULL}},
  {"ftruncate", "int", {"int", "off_t", NULL}},
  {"fchmod", "int", {"int", "mode_t", NULL}},
  {"fchown", "int", {"int", "uid_t", "gid_t", NULL}},
  {"getpriority", "int", {"int", "int", NULL}},
  {"setpriority", "int", {"int", "int", "int", "int", NULL}},
  {"profil", "int", {"unsigned short*", "size_t", "size_t", "unsigned int", NULL}},
  {"statfs", "int", {"char*", "struct statfs*", NULL}},
  {"fstatfs", "int", {"int", "struct statfs*", NULL}},
  {"ioperm", "int", {"unsigned long", "unsigned long", "int", NULL}},
  {"socketcall", "int", {"int", "unsigned long*", NULL}},
  {"syslog", "int", {"int", "char*", "int", NULL}},
  {"setitimer", "int", {"int", "struct itimerval*", "struct itimerval*", NULL}},
  {"getitimer", "int", {"int", "struct itimerval*", NULL}},
  {"stat", "int", {"char*", "struct stat*", NULL}},
  {"lstat", "int", {"char*", "struct stat*", NULL}},
  {"fstat", "int", {"int", "struct stat*", NULL}},
  {"olduname", NULL, {NULL}},
  {"iopl", "int", {"int", NULL}},
  {"vhangup", "int", {"void", NULL}},
  {"idle", NULL, {NULL}},
  {"vm86old", NULL, {NULL}},
  {"wait4", "pid_t", {"pid_t", "int*", "int", "struct rusage*", NULL}},
  {"swapoff", "int", {"char*", NULL}},
  {"sysinfo", "int", {"struct sysinfo*", NULL}},
  {"ipc", NULL, {NULL}},
  {"fsync", "int", {"int", NULL}},
  {"sigreturn", NULL, {NULL}},
  {"clone", "int", {"int (*)(void*)", "void*", "int", "void*", "...", NULL}},
  {"setdomainname", "int", {"char*", "size_t", NULL}},
  {"uname", "int", {"struct utsname*", NULL}},
  {"modify_ldt", "int", {"int", "void*", "unsigned long", NULL}},
  {"adjtimex", "int", {"struct timex*", NULL}},
  {"mprotect", "int", {"void*", "size_t", "int", NULL}},
  {"sigprocmask", NULL, {NULL}},
  {"create_module", "caddr_t", {"char*", "size_t", NULL}},
  {"init_module", "int", {"char*", "struct module*", NULL}},
  {"delete_module", "int", {"char*", NULL}},
  {"get_kernel_syms", "int", {"struct kernel_sym*", NULL}},
  {"quotactl", "int", {"int", "char*", "int", "caddr_t", NULL}},
  {"getpgid", "pid_t", {"pid_t", NULL}},
  {"fchdir", "int", {"int", NULL}},
  {"bdflush", NULL, {NULL}},
  {"sysfs", "int", {"int", NULL}},
  {"personality", "int", {"unsigned long", NULL}},
  {"afs_syscall", NULL, {NULL}},
  {"setfsuid", "int", {"uid_t", NULL}},
  {"setfsgid", "int", {"uid_t", NULL}},
  {"_llseek", NULL, {NULL}},
  {"getdents", "int", {"unsigned int", "struct linux_dirent*", "unsigned int", NULL}},
  {"select", "int", {"int", "fd_set*", "fd_set*", "fd_set*", "struct timeval*", NULL}},
  {"flock", "int", {"int", "int", NULL}},
  {"msync", "int", {"void*", "size_t", "int", NULL}},
  {"readv", "ssize_t", {"int", "struct iovec*", "int", NULL}},
  {"writev", "ssize_t", {"int", "struct iovec*", "int", NULL}},
  {"getsid", "pid_t", {"pid_t", NULL}},
  {"fdatasync", "int", {"int", NULL}},
  {"_sysctl", "int", {"struct __sysctl_args*", NULL}},
  {"mlock", "int", {"cont void*", "size_t", NULL}},
  {"munlock", "int", {"void*", "size_t", NULL}},
  {"mlockall", "int", {"int", NULL}},
  {"munlockall", "int", {"void", NULL}},
  {"sched_setparam", "int", {"pid_t", "struct sched_param*", NULL}},
  {"sched_getparam", "int", {"pid_t", "struct sched_param*", NULL}},
  {"sched_setscheduler", "int", {"pid_t", "int", "struct sched_param*", NULL}},
  {"sched_getscheduler", "int", {"pid_t", NULL}},
  {"sched_yield", "int", {"void", NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"nanosleep", "int", {"struct timespec*", "struct timespec*", NULL}},
  {"mremap", "void*", {"void*", "size_t", "size_t", "int", "...", NULL}},
  {"setresuid", "int", {"uid_t", "uid_t", "uid_t", NULL}},
  {"getresuid", "int", {"uid_t*", "uid_t*", "uid_t*", NULL}},
  {"vm86", NULL, {NULL}},
  {"query_module", "int", {"char*", "int", "void*", "size_t", "size_t", NULL}},
  {"poll", "int", {"struct pollfd*", "nfds_t", "int", NULL}},
  {"nfsservctl", "long", {"int", "struct nfsctl_arg*", "union nfsctl_res*", NULL}},
  {"setresgid", "int", {"gid_t", "gid_t", "gid_t", NULL}},
  {"getresgid", "int", {"gid_t*", "gid_t*", "gid_t*", NULL}},
  {"prctl", "int", {"int", "unsigned long", "unsigned long", "unsigned long", "unsigned long", NULL}},
  {"rt_sigreturn", "int", {"unsigned long", NULL}},
  {"rt_sigaction", "int", {"int", "struct sigaction*", "struct sigaction*", NULL}},
  {"rt_sigprocmask", "int", {"int", "sigset_t*", "sigset_t*", NULL}},
  {"rt_sigpending", "int", {"sigset_t*", NULL}},
  {"rt_sigtimedwait", "int", {"sigset_t*", "siginfo_t*", "struct timespec*", NULL}},
  {"", NULL, {NULL}},
  {"rt_sigsuspend", "int", {"sigset_t*", NULL}},
  {"pread64", "ssize_t", {"int", "void*", "size_t", "off_t", NULL}},
  {"pwrite64", "ssize_t", {"int", "void*", "size_t", "off_t", NULL}},
  {"chown", "int", {"char*", "uid_t", "gid_t", NULL}},
  {"getcwd", "char*", {"char*", "size_t", NULL}},
  {"capget", "int", {"cap_user_header_t", "cap_user_data_t", NULL}},
  {"capset", "int", {"cap_user_header_t", "cap_user_data_t", NULL}},
  {"sigaltstack", "int", {"stack_t*", "stack_t*", NULL}},
  {"sendfile", "ssize_t", {"int", "int", "off_t*", "size_t", NULL}},
  {"getpmsg", NULL, {NULL}},
  {"putpmsg", NULL, {NULL}},
  {"vfork", "pid_t", {"void", NULL}},
  {"getrlimit", "int", {"int", "struct rlimit*", NULL}},
  {"mmap2", NULL, {NULL}},
  {"truncate64", NULL, {NULL}},
  {"ftruncate64", NULL, {NULL}},
  {"stat64", NULL, {NULL}},
  {"lstat64", NULL, {NULL}},
  {"fstat64", NULL, {NULL}},
  {"lchown32", NULL, {NULL}},
  {"getuid32", NULL, {NULL}},
  {"getgid32", NULL, {NULL}},
  {"geteuid32", NULL, {NULL}},
  {"getegid32", NULL, {NULL}},
  {"setreuid32", NULL, {NULL}},
  {"setregid32", NULL, {NULL}},
  {"getgroups32", NULL, {NULL}},
  {"setgroups32", NULL, {NULL}},
  {"fchown32", NULL, {NULL}},
  {"setresuid32", NULL, {NULL}},
  {"getresuid32", NULL, {NULL}},
  {"setresgid32", NULL, {NULL}},
  {"getresgid32", NULL, {NULL}},
  {"chown32", NULL, {NULL}},
  {"setuid32", NULL, {NULL}},
  {"setgid32", NULL, {NULL}},
  {"setfsuid32", NULL, {NULL}},
  {"setfsgid32", NULL, {NULL}},
  {"pivot_root", "int", {"char*", "char*", NULL}},
  {"mincore", "int", {"void*", "size_t", "unsigned char*", NULL}},
  {"madvise", "int", {"void*", "size_t", "int", NULL}},
  {"getdents64", "int", {"unsigned int", "struct linux_dirent*", "unsigned int", NULL}},
  {"fcntl64", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"security", NULL, {NULL}},
  {"gettid", "pid_t", {"void", NULL}},
  {"readahead", "ssize_t", {"int", "off64_t", "size_t", NULL}},
  {"setxattr", "int", {"char*", "char*", "void*", "size_t", "int", NULL}},
  {"lsetxattr", "int", {"char*", "char*", "void*", "size_t", "int", NULL}},
  {"fsetxattr", "int", {"int", "char*", "void*", "size_t", "int", NULL}},
  {"getxattr", "ssize_t", {"char*", "char*", "void*", "size_t", NULL}},
  {"lgetxattr", "ssize_t", {"char*", "char*", "void*", "size_t", NULL}},
  {"fgetxattr", "ssize_t", {"int", "char*", "void*", "size_t", NULL}},
  {"listxattr", "ssize_t", {"char*", "char*", "size_t", NULL}},
  {"llistxattr", "ssize_t", {"char*", "char*", "size_t", NULL}},
  {"flistxattr", "ssize_t", {"int", "char*", "size_t", NULL}},
  {"removexattr", "int", {"char*", "char*", NULL}},
  {"lremovexattr", "int", {"char*", "char*", NULL}},
  {"fremovexattr", "int", {"int", "char*", NULL}},
  {"tkill", "int", {"int", "int", NULL}},
  {"sendfile64", NULL, {NULL}},
  {"futex", "int", {"int*", "int", "struct timespec*", "int*", "int", NULL}},
  {"sched_setaffinity", "int", {"pid_t", "size_t", "cpu_set_t*", NULL}},
  {"sched_getaffinity", "int", {"pid_t", "size_t", "cpu_set_t*", NULL}},
  {"set_thread_area", "int", {"struct user_desc*", NULL}},
  {"get_thread_area", "int", {"struct user_desc*", NULL}},
  {"io_setup", "int", {"unsigned", "aio_context_t*", NULL}},
  {"io_destroy", "int", {"aio_context_t", NULL}},
  {"io_getevents", "int", {"aio_context_t", "long", "long", "struct io_event*", "struct timespec*", NULL}},
  {"io_submit", "int", {"aio_context_t", "long", "struct iocb**", NULL}},
  {"io_cancel", "int", {"aio_context_t", "struct iocb*", "struct io_event*", NULL}},
  {"fadvise64", "int", {"int", "off_t", "off_t", "int", NULL}},
  {"", NULL, {NULL}},
  {"exit_group", "void", {"int", NULL}},
  {"lookup_dcookie", "int", {"u64", "char*", "size_t", NULL}},
  {"epoll_create", "int", {"int", NULL}},
  {"epoll_ctl", "int", {"int", "int", "int", "struct epoll_event*", NULL}},
  {"epoll_wait", "int", {"int", "struct epoll_event*", "int", "int", NULL}},
  {"remap_file_pages", "int", {"void*", "size_t", "int", "ssize_t", "int", NULL}},
  {"set_tid_address", "long", {"int*", NULL}},
  {"timer_create", "int", {"clockid_t", "struct sigevent*", "timer_t*", NULL}},
  {"timer_settime", "int", {"timer_t", "int", "struct itimerspec*", "struct itimerspec*", NULL}},
  {"timer_gettime", "int", {"timer_t", "struct itimerspec*", NULL}},
  {"timer_getoverrun", "int", {"timer_t", NULL}},
  {"timer_delete", "int", {"timer_t", NULL}},
  {"clock_settime", "int", {"clockid_t", "struct timespec*", NULL}},
  {"clock_gettime", "int", {"clockid_t", "struct timespec*", NULL}},
  {"clock_getres", "int", {"clockid_t", "struct timespec*", NULL}},
  {"clock_nanosleep", "int", {"clockid_t", "int", "struct timespec*", "struct timespec*", NULL}},
  {"statfs64", NULL, {NULL}},
  {"fstatfs64", NULL, {NULL}},
  {"tgkill", "int", {"int", "int", "int", NULL}},
  {"utimes", "int", {"char*", "struct timeval[2]", NULL}},
  {"fadvise64_64", NULL, {NULL}},
  {"vserver", NULL, {NULL}},
  {"mbind", "int", {"void*", "unsigned long", "int", "unsigned long*", "unsigned long", "unsigned", NULL}},
  {"get_mempolicy", "int", {"int*", "unsigned long*", "unsigned long", "unsigned long", "unsigned long", NULL}},
  {"set_mempolicy", "int", {"int", "unsigned long*", "unsigned long"}},
  {"mq_open", "mqd_t", {"char*", "int", NULL}},
  {"mq_unlink", "int", {"char*", NULL}},
  {"mq_timedsend", "int", {"mqd_t", "char*", "size_t", "unsigned", "struct timespec*", NULL}},
  {"mq_timedreceive", "ssize_t", {"mqd_t", "char*", "size_t", "unsigned*", "struct timespec*", NULL}},
  {"mq_notify", "int", {"mqd_t", "struct sigevent*", NULL}},
  {"mq_getsetattr", "int", {"mqd_t", "struct mq_attr*", "struct mq_attr*", NULL}},
  {"kexec_load", "long", {"unsigned long", "unsigned long", "struct kexec_segment*", "unsigned long", NULL}},
  {"waitid", "int", {"idtype_t", "id_t", "siginfo_t*", "int", NULL}},
  {"", NULL, {NULL}},
  {"add_key", "key_serial_t", {"char*", "char*", NULL}},
  {"request_key", "key_serial_t", {"char*", "char*", "char*", "key_serial_t", NULL}},
  {"keyctl", "long", {"int", "...", NULL}},
  {"ioprio_set", "int", {"int", "int", "int", NULL}},
  {"ioprio_get", "int", {"int", "int", NULL}},
  {"inotify_init", "int", {"void", NULL}},
  {"inotify_add_watch", "int", {"int", "char*", "uint32_t", NULL}},
  {"inotify_rm_watch", "int", {"int", "int", NULL}},
  {"migrate_pages", "long", {"int", "unsigned long", "unsigned long*", "unsigned long*", NULL}},
  {"openat", "int", {"int", "char*", "int", NULL}},
  {"mkdirat", "int", {"int", "char*", "mode_t", NULL}},
  {"mknodat", "int", {"int", "char*", "mode_t", "dev_t", NULL}},
  {"fchownat", "int", {"int", "char*", "uid_t", "gid_t", "int", NULL}},
  {"futimesat", "int", {"int", "char*", "struct timeval[2]", NULL}},
  {"fstatat64", NULL, {NULL}},
  {"unlinkat", "int", {"int", "char*", "int", NULL}},
  {"renameat", "int", {"int", "char*", "int", "char*", NULL}},
  {"linkat", "int", {"int", "char*", "int", "char*", "int", NULL}},
  {"symlinkat", "int", {"char*", "int", "char*", NULL}},
  {"readlinkat", "int", {"int", "char*", "char*", "size_t", NULL}},
  {"fchmodat", "int", {"int", "char*", "mode_t", "int", NULL}},
  {"faccessat", "int", {"int", "char*", "int", "int", NULL}},
  {"pselect6", "int", {"int", "fd_set*", "fd_set*", "fd_set*", "struct timespec*", "sigset_t*", NULL}},
  {"ppoll", "int", {"struct pollfd*", "nfds_t", "struct timespec*", "sigset_t*", NULL}},
  {"unshare", "int", {"int", NULL}},
  {"set_robust_list", "long", {"struct robust_list_head*", "size_t", NULL}},
  {"get_robust_list", "long", {"int", "struct robust_list_head**", "size_t*", NULL}},
  {"splice", "ssize_t", {"int", "loff_t*", "int", "loff_t*", "size_t", "unsigned int", NULL}},
  {"sync_file_range", "int", {"int", "off64_t", "off64_t", "unsigned int", NULL}},
  {"tee", "ssize_t", {"int", "int", "size_t", "unsigned int", NULL}},
  {"vmsplice", "ssize_t", {"int", "struct iovec*", "unsigned long", "unsigned int", NULL}},
  {"move_pages", "long", {"int", "unsigned long", "void**", "int*", "int*", "int", NULL}},
  {"getcpu", "int", {"unsigned*", "unsigned*", "struct getcpu_cache*", NULL}},
  {"epoll_pwait", "int", {"int", "struct epoll_event*", "int", "int", "sigset_t*", NULL}},
  {"utimensat", "int", {"int", "char*", "struct timespec[2]", "int", NULL}},
  {"signalfd", "int", {"int", "sigset_t*", "int", NULL}},
  {"timerfd_create", "int", {"int", "int", NULL}},
  {"eventfd", "int", {"unsigned int", "int", NULL}},
  {"fallocate", "int", {"int", "int", "off_t", "off_t", NULL}},
  {"timerfd_settime", "int", {"int", "int", "struct itimerspec*", "struct itimerspec*", NULL}},
  {"timerfd_gettime", "int", {"int", "struct itimerspec*", NULL}},
  {"signalfd4", "int", {"int", "sigset_t*", "int", NULL}},
  {"eventfd2", "int", {"unsigned int", "int", NULL}},
  {"epoll_create1", "int", {"int", NULL}},
  {"dup3", "int", {"int", "int", "int", NULL}},
  {"pipe2", "int", {"int[2]", "int", NULL}},
  {"inotify_init1", "int", {"int", NULL}},
  {"preadv", "ssize_t", {"int", "struct iovec*", "int", "off_t", NULL}},
  {"pwritev", "ssize_t", {"int", "struct iovec*", "int", "off_t", NULL}},
  {"rt_tgsigqueueinfo", NULL, {NULL}},
  {"perf_event_open", NULL, {NULL}},
  {"recvmmsg", NULL, {NULL}},
  {"fanotify_init", NULL, {NULL}},
  {"fanotify_mark", NULL, {NULL}},
  {"prlimit64", NULL, {NULL}},
  {"name_to_handle_at", NULL, {NULL}},
  {"open_by_handle_at", NULL, {NULL}},
  {"clock_adjtime", NULL, {NULL}},
  {"syncfs", NULL, {NULL}},
  {"sendmmsg", NULL, {NULL}},
  {"setns", NULL, {NULL}},
  {"process_vm_readv", NULL, {NULL}},
  {"process_vm_writev", NULL, {NULL}},
  {"kcmp", NULL, {NULL}},
  {"finit_module", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"", NULL, {NULL}},
  {"socket_subcall", NULL, {NULL}},
  {"socket", "int", {"int", "int", "int", NULL}},
  {"bind", "int", {"int", "struct sockaddr*", "socklen_t", NULL}},
  {"connect", "int", {"int", "struct sockaddr*", "socklen_t", NULL}},
  {"listen", "int", {"int", "int", NULL}},
  {"accept", "int", {"int", "struct sockaddr*", "socklen_t*", NULL}},
  {"getsockname", "int", {"int", "struct sockaddr*", "socklen_t*", NULL}},
  {"getpeername", "int", {"int", "struct sockaddr*", "socklen_t*", NULL}},
  {"socketpair", "int", {"int", "int", "int", "int*", NULL}},
  {"send", NULL, {NULL}},
  {"recv", NULL, {NULL}},
  {"sendto", "ssize_t", {"int", "void*", "size_t", "int", NULL}},
  {"recvfrom", "ssize_t", {"int", "void*", "size_t", "int", "struct sockaddr*", "socklen_t*", NULL}},
  {"shutdown", "int", {"int", "int", NULL}},
  {"setsockopt", "int", {"int", "int", "int", "void*", "socklen_t", NULL}},
  {"getsockopt", "int", {"int", "int", "int", "void*", "socklen_t*", NULL}},
  {"sendmsg", "ssize_t", {"int", "struct msghdr*", "int", NULL}},
  {"recvmsg", "ssize_t", {"int", "struct msghdr*", "int", NULL}},
  {"accept4", "int", {"int", "struct sockaddr*", "socklen_t*", "int", NULL}},
  {"recvmmsg", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"semop", "int", {"int", "struct sembuf*", "unsigned", NULL}},
  {"semget", "int", {"key_t", "int", "int", NULL}},
  {"semctl", "int", {"int", "int", "int", NULL}},
  {"semtimedop", "int", {"int", "struct sembuf*", "unsigned", "struct timespec*", NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"msgsnd", "int", {"int", "void*", "size_t", "int", NULL}},
  {"msgrcv", "ssize_t", {"int", "void*", "size_t", "long", "int", NULL}},
  {"msgget", "int", {"key_t", "int", NULL}},
  {"msgctl", "int", {"int", "int", "struct msqid_ds*", NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"ipc_subcall", NULL, {NULL}},
  {"shmat", "void*", {"int", "void*", "int", NULL}},
  {"shmdt", "int", {"void*", NULL}},
  {"shmget", "int", {"key_t", "size_t", "int", NULL}},
  {"shmctl", "int", {"int", "int", "struct shmid_ds*", NULL}}
};

#endif /* !SYSCALL_X86_H_INCLUDED */
