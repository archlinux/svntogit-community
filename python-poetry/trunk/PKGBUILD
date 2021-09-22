# Maintainer: Eli Schwartz <eschwartz@archlinux.org>
# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>

_pkgname=poetry
pkgname=python-poetry
pkgver=1.1.10
pkgrel=1
pkgdesc="Python dependency management and packaging made easy"
arch=('any')
url="https://poetry.eustace.io/"
license=('MIT')
_deps=('cachecontrol' 'cachy' 'cleo' 'html5lib' 'lockfile'
       'packaging' 'pkginfo' 'poetry-core' 'requests' 'requests-toolbelt'
       'shellingham' 'tomlkit' 'keyring' 'pexpect' 'virtualenv')
depends=("${_deps[@]/#/python-}")
makedepends=('python-dephell')
checkdepends=('git' 'python-pytest' 'python-pytest-mock' 'python-httpretty')
provides=('poetry')
conflicts=('poetry')
replaces=('poetry')
source=("${_pkgname}-${pkgver}.tar.gz::https://github.com/sdispater/${_pkgname}/archive/${pkgver}.tar.gz"
        "0001-Suppress-dependency-versions-which-are-known-to-be-t.patch"
        "0001-tests-cleanup-cache-and-http-usage.patch"
        "poetry-completions-generator")
sha256sums=('fbe606581dcf2200d63d15c3fc8d2b24895f459d805c9c8b62e8061b9409f31b'
            '8bb321ae9ad06d4829c71727af7979bc68d7f325ccdaec919dda4fe8ac92f1a7'
            '4658321c04f36fb3aced9acc44b61f2cf22c5f9d8b8c715111881b24c3e0c99b'
            '970225289188ea8dc49fbec8a2bfe0c891aee80ff56ba6e69bdd8afef8bccab6')
b2sums=('b65dd506eaefea49db20aafd21fcf7a48178625686f6f412cb97e76e8e8366a79843a2ee13550e4822828694c2bf8f17b7fb31be94a2e1197344b2d363cfef7a'
        'c1c65fdfa1153d3e4c872adc00f02aea055268d28cd385918a5a3d60fb355c39b15eab895cf4aebd1b74f126cc225f870d60aa971a6593855ce094b448786a02'
        '8750de6ee2748a7dac079af1ff35b43dbce3f2c48249322f3322290d03f46ea95513dfd223adc232f7f73cf0ac19554de96a3b8793a0dc13b38041e87569ca19'
        '3fd62e7936d7547dcd06a1a7519f176a1597553ecc959144a4be799bb7e2d688e187f14604d3e359ed10c128c722ebd588c07ca318e0be0a31d276dcb388e2e1')

prepare() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # fix various overly restrictive version pinning
    patch -p1 -i ../0001-Suppress-dependency-versions-which-are-known-to-be-t.patch

    # fix tests trying to write to the root directory
    # See: https://github.com/python-poetry/poetry/issues/1645
    patch -p1 -i ../0001-tests-cleanup-cache-and-http-usage.patch

    dephell deps convert --from pyproject.toml --to setup.py
}

build() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    # tries to write all over sys.executable's containing directory, and fails
    # use venv instead
    # See (again): https://github.com/python-poetry/poetry/issues/1645
    # python -m venv --system-site-packages --without-pip poetrytests
    # ./poetrytests/bin/python -m pytest
}

package() {
    cd "${srcdir}"/${_pkgname}-${pkgver}

    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build
    install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

    # install completions, which for some crazy reason hardcode the filename
    # used to invoke which is __main__.py if we use python -m poetry, and also
    # adds the full directory path???
    install -m755 "${srcdir}"/poetry-completions-generator ./poetry-completions-generator
    ./poetry-completions-generator completions bash | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/bash-completion/completions/poetry
    ./poetry-completions-generator completions zsh | sed "\|${srcdir}|d" | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/zsh/site-functions/_poetry
    ./poetry-completions-generator completions fish | \
        install -Dm644 /dev/stdin "${pkgdir}"/usr/share/fish/vendor_completions.d/poetry.fish
}
