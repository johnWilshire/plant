context("StochasticPatch")

strategy_types <- get_list_of_strategy_types()

test_that("empty", {
  for (x in names(strategy_types)) {
    p <- Parameters(x)(strategies=list(strategy_types[[x]]()),
                          seed_rain=pi/2,
                          is_resident=TRUE)
    patch <- StochasticPatch(x)(p)

    expect_is(patch, sprintf("StochasticPatch<%s>",x))

    expect_equal(patch$size, 1)
    expect_equal(patch$height_max, 0.0)
    expect_equal(patch$canopy_openness(0), 1.0)
    expect_equal(patch$ode_state, numeric(0))
    expect_equal(patch$ode_rates, numeric(0))

    sp <- patch$species
    expect_true(is.list(sp))
    expect_equal(length(sp), 1)
    expect_is(sp[[1]], sprintf("StochasticSpecies<%s>",x))
    expect_equal(sp[[1]]$size, 0)
  }
})

test_that("non empty", {
  for (x in names(strategy_types)) {
    p <- Parameters(x)(strategies=list(strategy_types[[x]]()),
                          seed_rain=pi/2,
                          is_resident=TRUE)
    patch <- StochasticPatch(x)(p)
    cmp <- Plant(x)(p$strategies[[1]])

    expect_error(patch$add_seed(0), "Invalid value")
    expect_error(patch$add_seed(10), "out of bounds")

    expect_true(patch$add_seed(1))
    expect_gt(patch$height_max, 0.0)
    expect_equal(patch$height_max, cmp$height)

    expect_equal(patch$deaths(), 0)

    le <- patch$environment$light_environment
    expect_equal(range(le$x), c(0.0, cmp$height))
    expect_equal(max(le$y), 1.0)
    expect_lt(le$y[[1]], 1.0)

    if (x == "FF16") {
      expect_true(all(patch$ode_rates > 0.0))
    } else if (x == "FF16r") {
      expect_true(all(patch$ode_rates[-3] > 0.0))
      expect_equal(patch$ode_rates[[3]], 0)
    }
  }
})
