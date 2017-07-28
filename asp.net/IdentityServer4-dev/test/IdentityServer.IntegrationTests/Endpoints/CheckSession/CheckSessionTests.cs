﻿// Copyright (c) Brock Allen & Dominick Baier. All rights reserved.
// Licensed under the Apache License, Version 2.0. See LICENSE in the project root for license information.


using FluentAssertions;
using IdentityServer4.IntegrationTests.Common;
using System.Net;
using System.Threading.Tasks;
using Xunit;

namespace IdentityServer4.IntegrationTests.Endpoints.CheckSession
{
    public class CheckSessionTests
    {
        const string Category = "Check session endpoint";

        MockIdSvrUiPipeline _mockPipeline = new MockIdSvrUiPipeline();

        public CheckSessionTests()
        {
            _mockPipeline.Initialize();
        }

        [Fact]
        [Trait("Category", Category)]
        public async Task get_request_should_not_return_404()
        {
            var response = await _mockPipeline.Client.GetAsync(MockIdSvrUiPipeline.CheckSessionEndpoint);

            response.StatusCode.Should().NotBe(HttpStatusCode.NotFound);
        }
    }
}
