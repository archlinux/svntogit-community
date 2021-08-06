# Maintainer: Tim Meusel <tim@bastelfreak.de>

_gemname='rspec-its'
pkgname="ruby-${_gemname}"
pkgver=1.3.0
pkgrel=5
pkgdesc='RSpec extension gem for attribute matching'
arch=('any')
url='https://github.com/rspec/rspec-its'
license=('MIT')
makedepends=('ruby-rdoc')
checkdepends=('ruby-rake' 'ruby-minitest' 'ruby-test-unit')
depends=('ruby' 'ruby-rspec')
options=(!emptydirs)
source=("${url}/archive/v${pkgver}/${pkgname}-v${pkgver}.tar.gz"
        'disable-cucumber.patch')
sha512sums=('97be9ba1f46db44a3d60676056d5ad66ee84585ff133ffaf25c42fc1e899c33d9841a9440336a8bd52c58685d8b2b5505c5cef7bfb5d634bcbc370c4b1a8a287'
            '024e9ffecb7f366ddfc87b90dc3a1dbc897c6baadf466930c27255fd41617baccecbafea91e0cd292c8437737a9cdc596d012423982433d59eb45024e4c5b31a')

prepare() {
  cd "${srcdir}/${_gemname}-${pkgver}"

  # we build with a tar archive, so `git` won't work
  sed --in-place 's|`git ls-files`.split($/)|`find`.split("\\n")|' "${_gemname}.gemspec"

  # disable unneeded dependencies
  patch --forward --verbose --strip=1 --input='../disable-cucumber.patch'
  sed --in-place '/.*dependency.*cucumber/d' "${_gemname}.gemspec"
  sed --in-place '/aruba/d' "${_gemname}.gemspec"
  sed --in-place '/bundler/d' "${_gemname}.gemspec"
}

build() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  rake spec
}

package() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}

# vim: ts=2 sw=2 et:
