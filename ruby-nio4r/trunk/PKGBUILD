# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname=nio4r
pkgname=ruby-${_gemname}
pkgver=2.5.8
pkgrel=1
pkgdesc='Abstract, cross-platform stateful I/O selector API for Ruby'
url='https://github.com/celluloid/nio4r'
arch=('x86_64')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc' 'git')
checkdepends=('ruby-bundler' 'ruby-rake' 'ruby-rake-compiler' 'ruby-rspec')
options=('!emptydirs')
source=("https://github.com/celluloid/nio4r/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz"
        # https://github.com/socketry/nio4r/issues/283
        nio4r_fix_openssl_tests.patch)
sha512sums=('a90d774468189667727345d9edfe70922f4887d89b7afb884033e1b38b7002400bed573f277ce7cc3e5fc5cbc69192ae36ad093ec3dd25f995df9b7768498e4c'
            '2a0e610acb4fd4d06a7053dee6910fb717dc811f0957828f3cea327ed9d41e0bb8cba2eb0a3e58bb074e73395921f7f3c4771750624b248011ce35859a7dd99c')
b2sums=('95ae433051a58779d5039c97d456e8fbf81acd4de38c9d98d33c55a1000ab5e0fafb313982b53d9b3f10fb260b859598935a061205d22054cbf99d03f9941090'
        '57ff0dfb26e96c7e19366b1c528b31043e327d3318fa02d90da58e2d2df3019c5b2a969dcc27087866dc4e63082a978ceb9fb0459e9526c8fd6d435d8693dc02')

prepare() {
  cd "${_gemname}-${pkgver}"

  patch --verbose --strip=1 --input=../nio4r_fix_openssl_tests.patch

  sed 's|git ls-files|find|' -i "${_gemname}.gemspec"

  sed --in-place '/coveralls/Id' spec/spec_helper.rb

  rm rakelib/rubocop.rake
}

build() {
  cd "${_gemname}-${pkgver}"

  rake compile build
}

check() {
  cd "${_gemname}-${pkgver}"

  rake spec
}

package() {
  cd ${_gemname}-${pkgver}

  local _gemdir="$(gem env gemdir)"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" \
    -n "${pkgdir}/usr/bin" "pkg/${_gemname}-${pkgver}.gem"

  install -Dm 644 README.md CHANGES.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 README.md -t "${pkgdir}/usr/share/licenses/${pkgname}"

  cp -r examples "${pkgdir}/usr/share/doc/${pkgname}"

  cd "${pkgdir}/${_gemdir}"
  rm -rf cache \
    "gems/${_gemname}-${pkgver}/tmp/" \
    "gems/${_gemname}-${pkgver}/ext/${_gemname}/Makefile" \
    extensions/*/*/${_gemname}-${pkgver}/{mkmf.log,gem_make.out} \
    "${pkgdir}/${_gemdir}/doc/${_gemname}-${pkgver}/ri/ext/"
}

# vim: ts=2 sw=2 et:
