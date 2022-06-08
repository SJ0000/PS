from collections import deque
import heapq


def solution(jobs):

    heap = []
    job_queue = deque(sorted(jobs))

    time = 0
    answer = 0

    # current = [전체 작업시간,요청받은 시간, 남은 작업 시간]
    current = None

    while not (len(job_queue) == 0 and len(heap) == 0 and current == None):
        # job_queue에서 heap으로 작업 할당
        while True:
            if len(job_queue) == 0:
                break

            [req_time, work_time] = job_queue[0]
            if req_time == time:
                heapq.heappush(heap, (work_time, req_time))
                job_queue.popleft()
            else:
                break

        # 작업이 있으면 작업
        if current != None:
            current[2] -= 1
            if current[2] == 0:
                # print("작업 완료", time, current)
                answer += (time - current[1])
                current = None

        # 현재 작업이 없고, 대기작업이 있으면 작업
        if current == None and len(heap) > 0:
            (current_work_time, current_req_time) = heapq.heappop(heap)
            current = [current_work_time, current_req_time, current_work_time]
            # print("작업 할당", time, current)

        time += 1

    return answer//len(jobs)


print(solution([[0, 3], [1, 9], [2, 6]]))
