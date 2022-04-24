# Maintainer: Tim Meusel <tim at bastelfreak dot de>
# Contributor: Mario Finelli <mario at finel dot li>

_gemname=fast_gettext
pkgname=ruby-${_gemname}
pkgver=2.2.0
pkgrel=1
pkgdesc='A simple, fast, memory-efficient and threadsafe implementation of GetText'
arch=(any)
url='https://github.com/grosser/fast_gettext'
license=(MIT RUBY)
makedepends=(ruby-rdoc ruby-rake ruby-rspec ruby-bundler)
depends=(ruby)
source=("https://github.com/grosser/fast_gettext/archive/v${pkgver}/${_gemname}-v${pkgver}.tar.gz")
options=(!emptydirs)
sha512sums=('06daacf46e4c8ef272ac2a60f8fad1abbb3eaa2bf5242991e7f32fd87e911917b6baf4965b0cbc96c11d0be0425585d501258d0c1faa065469dea6c3b8c97797')

# disable cloud metric reporting during tests
prepare() {
  cd "${_gemname}-${pkgver}"

  sed -i '/single_cov/d' spec/spec_helper.rb
  sed -i '/SingleCov.setup/d' spec/spec_helper.rb
  sed -i '/SingleCov/d' spec/fast_gettext/*.rb
  sed -i '/SingleCov/d' spec/fast_gettext/translation_repository/*.rb
}

build() {
  cd "${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  # tests currently disabled because active-record isn't available as package
  # rspec
}

package() {
  cd "${_gemname}-${pkgver}"
  local _gemdir="$(ruby -e'puts Gem.default_dir')"

  gem install \
    --ignore-dependencies \
    --no-user-install \
    -i "$pkgdir/$_gemdir" \
    -n "$pkgdir/usr/bin" \
    $_gemname-$pkgver.gem

  rm "$pkgdir/$_gemdir/cache/$_gemname-$pkgver.gem"

  # no license file provided in the source
  install -Dm 644 Readme.md CHANGELOG -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}/"
}
