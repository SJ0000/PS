

def solution(tickets):
    answer = []
    graph = dict()

    for [fr, to] in tickets:
        if graph.get(fr) == None:
            graph[fr] = []
        graph[fr].append(to)

    for fr in graph.keys():
        graph[fr] = sorted(graph[fr])

    def get_ticket_counts(graph):
        count = 0
        for key in graph.keys():
            count += len(graph[key])
        return count

    def dfs(node):
        answer.append(node)
        # print("dfs", node, answer)
        if get_ticket_counts(graph) == 0:
            # print("completed")
            return True

        if graph.get(node) == None or len(graph[node]) == 0:
            return False

        for next in graph[node][:]:
            graph[node].remove(next)
            completed = dfs(next)

            if completed:
                return True
            else:
                graph[node].append(next)
                answer.pop()
                # print("not completed", node, next, answer)

    dfs("ICN")
    # print("answer", answer, g)
    return answer


print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], [
      "ATL", "ICN"], ["ATL", "SFO"]]) == ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"])
print(solution([["ICN", "AOO"], ["AOO", "BOO"], ["BOO", "COO"], ["COO", "DOO"], ["DOO", "EOO"], ["EOO", "DOO"], [
      "DOO", "COO"], ["COO", "BOO"], ["BOO", "AOO"]]) == ["ICN", "AOO", "BOO", "COO", "DOO", "EOO", "DOO", "COO", "BOO", "AOO"])
print(solution([["ICN", "AOO"], ["AOO", "BOO"], ["AOO", "COO"], [
      "COO", "AOO"], ["BOO", "ZOO"]]) == ["ICN", "AOO", "COO", "AOO", "BOO", "ZOO"])
print(solution([["ICN", "AOO"], ["AOO", "BOO"], ["AOO", "BOO"], ["BOO", "AOO"], ["BOO", "FOO"], [
      "FOO", "COO"], ["COO", "ZOO"]]) == ["ICN", "AOO", "BOO", "AOO", "BOO", "FOO", "COO", "ZOO"])
print(solution([["ICN", "BOO"], ["ICN", "COO"], ["COO", "DOO"], ["DOO", "COO"], ["BOO", "DOO"], ["DOO", "BOO"], [
      "BOO", "ICN"], ["COO", "BOO"]]) == ["ICN", "BOO", "DOO", "BOO", "ICN", "COO", "DOO", "COO", "BOO"])
print(solution([["ICN", "AAA"], ["ICN", "AAA"], ["ICN", "AAA"], [
      "AAA", "ICN"], ["AAA", "ICN"]]) == ["ICN", "AAA", "ICN", "AAA", "ICN", "AAA"])
print(solution([["ICN", "BBB"], ["ICN", "CCC"], ["BBB", "CCC"], [
      "CCC", "BBB"], ["CCC", "ICN"]]) == ["ICN", "BBB", "CCC", "ICN", "CCC", "BBB"])
print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]])
      == ["ICN", "JFK", "HND", "IAD"])
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], [
      "ATL", "ICN"], ["ATL", "SFO"]]) == ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"])
print(solution([["ICN", "AOO"], ["ICN", "AOO"], ["AOO", "ICN"],
      ["AOO", "COO"]]) == ["ICN", "AOO", "ICN", "AOO", "COO"])
print(solution([["ICN", "AAA"], ["ICN", "AAA"], ["ICN", "AAA"], [
      "AAA", "ICN"], ["AAA", "ICN"]]) == ["ICN", "AAA", "ICN", "AAA", "ICN", "AAA"])
print(solution([["ICN", "BOO"], ["ICN", "COO"], ["COO", "DOO"], ["DOO", "COO"], ["BOO", "DOO"], ["DOO", "BOO"], [
      "BOO", "ICN"], ["COO", "BOO"]]) == ["ICN", "BOO", "DOO", "BOO", "ICN", "COO", "DOO", "COO", "BOO"])
